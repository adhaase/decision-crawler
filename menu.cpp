#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>

#include <windows.h> // WinApi header
#include "menu.h"
#include "hero.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void UI::printHeader() {

	// pick the color attribute k you want
	SetConsoleTextAttribute(hConsole, 11);

	std::cout << "--------------------------------------------------------------------\n";
	std::cout << "|             DUNGEON AUTOMATED CRAWLER | ver 1.0                  |\n";
	std::cout << "|                  Survive as long as you can!                     |\n";
	std::cout << "|                         by Alex Haase                            |\n";
	std::cout << "--------------------------------------------------------------------\n";
	std::cout << "\n";
}

static void printSkillCategoryInfo() {
	std::cout << "The skill categories are: ";
	SetConsoleTextAttribute(hConsole, 10); // light green
	std::cout << "VITALITY ";
	SetConsoleTextAttribute(hConsole, 12); // light red
	std::cout << "ATTACK ";
	SetConsoleTextAttribute(hConsole, 11); // light cyan
	std::cout << "AGILITY ";
	SetConsoleTextAttribute(hConsole, 14); // yellow
	std::cout << "LUCK";
	SetConsoleTextAttribute(hConsole, 15); // white

	std::cout << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 10); // light green
	std::cout << "VITALITY: Your health pool, when this falls to 0, you die. You start with a default health of 25 HP.\n";
	SetConsoleTextAttribute(hConsole, 12); // light red
	std::cout << "ATTACK: How much damage you do to enemies. The faster you kill incoming enemies, the faster you can proceed with the dungeon.\n";
	SetConsoleTextAttribute(hConsole, 11); // light cyan
	std::cout << "AGILITY: Increases your evasiveness allowing you to avoid enemies. Doesn't matter how much damage the enemies do if they can't hit ya!\n";
	SetConsoleTextAttribute(hConsole, 14); // yellow
	std::cout << "LUCK: Increases your ability to find new items and tools allowing you to progress through the dungeon faster.\n";
	SetConsoleTextAttribute(hConsole, 15); //reset console color back to white

	std::cout << std::endl << std::endl;
}

void UI::printIntro() {
	SetConsoleTextAttribute(hConsole, 15); //reset console color back to white

	std::cout << "Welcome brave hero! I'm about to send you down into a 10 story dungeon! MUHAHA! ";
	std::cout << "Don't worry though, I'll give you 20 skill points, allowing you to customize your favorite attributes to allow the best chance for survival! ";
	std::cout << "Each floor gets more and more intense, however, you will have a chance of picking up rare items to aid in your quest! ";
	std::cout << "Make it to floor 10 to receive your reward! ";
	std::cout << std::endl << std::endl;

	char skillCategoryChoice = '/0';
	std::cout << "Are you ready to hear about these skill categories? (y/n): ";
	std::cin >> skillCategoryChoice;
	switch (skillCategoryChoice) {
	case 'y':
		printSkillCategoryInfo();
		break;
	case 'n':
		std::cout << "Alright then, use your skill points wisely!\n";
		break;
	default:
		SetConsoleTextAttribute(hConsole, 12); // light red
		std::cout << "ERROR: You need to enter a valid choice (y/n).\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
}

// validate user input with respect to current allowed Skill Points
static bool checkUserInput(int &numPoints, int &skillPoints) {
	// user enters a number between skillPoints and 0
	
	if (numPoints > skillPoints) {
		SetConsoleTextAttribute(hConsole, 12); // light red
		std::cout << "ERROR: You can't enter a number greater than your allowed skill points!\n";
		SetConsoleTextAttribute(hConsole, 15);
		return false;
	}
	else if (numPoints < 0) {
		SetConsoleTextAttribute(hConsole, 12); // light red
		std::cout << "ERROR: You can't enter a negative value.\n";
		SetConsoleTextAttribute(hConsole, 15);
		return false;
	}
	else return true;
}

static void distribute(
	Hero &h, 
	char option, 
	int &numPoints, 
	int &skillPoints) {

	std::cin >> numPoints;
	bool status = checkUserInput(numPoints, skillPoints);
	if (status == true) {
		skillPoints -= numPoints;
		if (option == 'h') h.setvitality(25 + numPoints, h);
		else if (option == 'a') h.setAttack(5 + numPoints, h);
		else if (option == 'g') h.setAgility(5 + numPoints, h);
		else h.setLuck(5 + numPoints, h);
	}
}

static void executeSkillPointDistribution(
	Hero &h, 
	char option, // h, a, g, l {vitality, attack, agility, luck}
	int &numPoints, 
	int &skillPoints) {

	std::string attribute = "";
	switch (option) {
	case 'h':
		attribute = "vitality";
		SetConsoleTextAttribute(hConsole, 10); // light green
		break;
	case 'a':
		attribute = "attack";
		SetConsoleTextAttribute(hConsole, 12); // light red
		break;
	case 'g':
		attribute = "agility";
		SetConsoleTextAttribute(hConsole, 11); // light cyan
		break;
	case 'l':
		attribute = "luck";
		SetConsoleTextAttribute(hConsole, 14); // yellow
		break;
	default:
		break;
	}

	std::cout << "\n";
	std::cout << "How many skill points do you want to place in " << attribute << "?\n";
	std::cout << "Enter a number between 0 and " << skillPoints << ": ";

	std::cin >> numPoints;
	bool status = checkUserInput(numPoints, skillPoints);
	if (status == true) {
		skillPoints -= numPoints;
		if (option == 'h') h.setvitality(25 + numPoints, h);
		else if (option == 'a') h.setAttack(5 + numPoints, h);
		else if (option == 'g') h.setAgility(5 + numPoints, h);
		else h.setLuck(5 + numPoints, h);
	}
	else {
		std::cout << "Re-enter an appropriate value for " << attribute << ": ";
		if (option == 'h') distribute(h, 'h', numPoints, skillPoints);
		else if (option == 'a') distribute(h, 'a', numPoints, skillPoints);
		else if (option == 'g') distribute(h, 'g', numPoints, skillPoints);
		else distribute(h, 'l', numPoints, skillPoints);
	}

	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "New " << attribute << " value: ";
	switch (option) {
	case 'h':
		h.printvitality(h);
		break;
	case 'a':
		h.printAttack(h);
		break;
	case 'g':
		h.printAgility(h);
		break;
	case 'l':
		h.printLuck(h);
		break;
	default:
		break;
	}
	std::cout << std::endl;
}

void Distribution::distributeSkillPoints(Hero &h) {
	int skillPoints = 20;
	int vitalityPoints = 0;
	int attackPoints = 0;
	int agilityPoints = 0;
	int luckPoints = 0;

	// vitality point distribution
	executeSkillPointDistribution(h, 'h', vitalityPoints, skillPoints);

	// attack point distribution
	executeSkillPointDistribution(h, 'a', attackPoints, skillPoints);

	// agility point distribution
	executeSkillPointDistribution(h, 'g', agilityPoints, skillPoints);

	// luck point distribution
	executeSkillPointDistribution(h, 'l', luckPoints, skillPoints);
}

void Distribution::heroStatsConversation(Hero &h, Distribution &d) {
	char choice = '/0';
	std::cout << "Are you ready to proceed (p), or do you want to quit (q)? : ";
	std::cin >> choice;
	switch (choice) {
	case 'p':
		break;
	case 'q':
		exit(0);
		break;
	default:
		exit(0);
	}

	std::cout << "Let's take a look at your current stats: \n";
	std::cout << "Loading ";
	for (int i = 0; i < 3; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(750)); // SUSPENSE!
		std::cout << ".";
	}
	std::cout << std::endl;
	h.printHeroStats(h);
	std::cout << std::endl;
	std::cout << "Damn you're weak! Yeah buddy, here are those 20 skill points. Put them in whichever category you want!\n";
	std::cout << "If you want to play on hard-mode, you don't even have to use all of 20 available points!\n";
	d.distributeSkillPoints(h);

	// print updated hero stats
	std::cout << "Here are your updated hero stats after applying the 20 skill ponits!\n";
	h.printHeroStats(h);
}