#include <iostream>
#include <windows.h> // WinApi header
#include "menu.h"
#include "hero.h"

void UI::printHeader() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// pick the color attribute k you want
	SetConsoleTextAttribute(hConsole, 11);

	std::cout << "--------------------------------------------------------------------\n";
	std::cout << "|             DUNGEON AUTOMATED CRAWLER | ver 1.0                  |\n";
	std::cout << "|                  Survive as long as you can!                     |\n";
	std::cout << "|                         by Alex Haase                            |\n";
	std::cout << "--------------------------------------------------------------------\n";
	std::cout << "\n";
}

void UI::printIntro() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15); //reset console color back to white

	std::cout << "Welcome brave hero! I'm about to send you down into a 10 story dungeon! MUHAHA! ";
	std::cout << "Don't worry though, I'll give you 20 skill points, allowing you to customize your favorite attributes to allow the best chance for survival! ";
	std::cout << "Each floor gets more and more intense, however, you will have a chance of picking up rare items to aid in your quest! ";
	std::cout << "Make it to floor 10 to receive your reward! ";
	std::cout << std::endl << std::endl;

	std::cout << "The skill categories are: ";
	SetConsoleTextAttribute(hConsole, 10); // light green
	std::cout << "HEALTH ";
	SetConsoleTextAttribute(hConsole, 12); // light red
	std::cout << "ATTACK ";
	SetConsoleTextAttribute(hConsole, 9); // light blue
	std::cout << "AGILITY ";
	SetConsoleTextAttribute(hConsole, 14); // yellow
	std::cout << "LUCK";
	SetConsoleTextAttribute(hConsole, 15); // white

	std::cout << std::endl << std::endl;

	SetConsoleTextAttribute(hConsole, 10); // light green
	std::cout << "HEALTH: Your health pool, when this falls to 0, you die. You start with a default health of 25 HP.\n";
	SetConsoleTextAttribute(hConsole, 12); // light red
	std::cout << "ATTACK: How much damage you do to enemies. The faster you kill incoming enemies, the faster you can proceed with the dungeon.\n";
	SetConsoleTextAttribute(hConsole, 9); // light blue
	std::cout << "AGILITY: Increases your evasiveness allowing you to avoid enemies. Doesn't matter how much damage the enemies do if they can't hit ya!\n";
	SetConsoleTextAttribute(hConsole, 14); // yellow
	std::cout << "LUCK: Increases your ability to find new items and tools allowing you to progress through the dungeon faster.\n";
	SetConsoleTextAttribute(hConsole, 15); //reset console color back to white

	std::cout << std::endl << std::endl;
}

void Distribution::distributeSkillPoints(Hero &h) {
	int skillPoints = 20;
	int healthPoints = 0;
	int attackPoints = 0;
	int agilityPoints = 0;
	int luckPoints = 0;

	// health point distribution
	std::cout << "How many skill points do you want to place in Health?\n";
	std::cout << "Enter a number between " << skillPoints << " and 0: ";
	std::cin >> healthPoints;
	skillPoints -= healthPoints;
	h.setHealth(25 + healthPoints, h);
	std::cout << "New Health value: ";
	h.printHealth(h);
	std::cout << std::endl;

	// attack point distribution
	std::cout << "How many skill points do you want to place in Attack?\n";
	std::cout << "Enter a number between " << skillPoints << " and 0: ";
	std::cin >> attackPoints;
	skillPoints -= attackPoints;
	h.setAttack(5 + attackPoints, h);
	std::cout << "New Attack value: ";
	h.printAttack(h);
	std::cout << std::endl;

	// agility point distribution
	std::cout << "How many skill points do you want to place in Agility?\n";
	std::cout << "Enter a number between " << skillPoints << " and 0: ";
	std::cin >> agilityPoints;
	skillPoints -= agilityPoints;
	h.setAgility(5 + agilityPoints, h);
	std::cout << "New Agility value: ";
	h.printAgility(h);
	std::cout << std::endl;

	// luck point distribution
	std::cout << "How many skill points do you want to place in Luck?\n";
	std::cout << "Enter a number between " << skillPoints << " and 0: ";
	std::cin >> luckPoints;
	skillPoints -= luckPoints;
	h.setLuck(5 + luckPoints, h);
	std::cout << "New Luck value: ";
	h.printLuck(h);
	std::cout << std::endl;
}

void Distribution::heroStatsConversation(Hero &h, Distribution &d) {
	std::cout << "Let's take a look at your current stats: \n";
	h.printHeroStats(h);
	std::cout << std::endl;
	std::cout << "Damn you're weak! Yeah buddy, here's those 20 skill points. Put them in whichever category you want!\n";
	d.distributeSkillPoints(h);

	// print updated hero stats
	std::cout << "Here are your updated hero stats after applying the 20 skill ponits!\n";
	h.printHeroStats(h);
}