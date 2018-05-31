#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <windows.h> // WinApi header

#include "hero.h"

Hero::Hero() {
	vitality = 25;
	attack = 5;
	agility = 5;
	luck = 5;
}

void Hero::setvitality(int vitality, Hero &h) {
	h.vitality = vitality;
}
void Hero::setAttack(int attack, Hero &h) {
	h.attack = attack;
}
void Hero::setAgility(int agility, Hero &h) {
	h.agility = agility;
}
void Hero::setLuck(int luck, Hero &h) {
	h.luck = luck;
}

void Hero::printvitality(Hero &h) {
	std::cout << h.vitality;
}
void Hero::printAttack(Hero &h) {
	std::cout << h.attack;
}
void Hero::printAgility(Hero &h) {
	std::cout << h.agility;
}
void Hero::printLuck(Hero &h) {
	std::cout << h.luck;
}

void Hero::printHeroStats(Hero &h) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10); // light green
	std::cout << "VITALITY: " << h.vitality << std::endl;
	SetConsoleTextAttribute(hConsole, 12); // light red
	std::cout << "ATTACK: " << h.attack << std::endl;
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << "AGILITY: " << h.agility << std::endl;
	SetConsoleTextAttribute(hConsole, 14); // yellow
	std::cout << "LUCK: " << h.luck << std::endl;
	SetConsoleTextAttribute(hConsole, 15); // white
}