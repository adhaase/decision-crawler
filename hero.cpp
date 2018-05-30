#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <windows.h> // WinApi header

#include "hero.h"

Hero::Hero() {
	health = 25;
	attack = 5;
	agility = 5;
	luck = 5;
}

void Hero::setHealth(int health, Hero &h) {
	h.health = health;
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

void Hero::printHealth(Hero &h) {
	std::cout << h.health;
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
	std::cout << "HEALTH: " << h.health << std::endl;
	SetConsoleTextAttribute(hConsole, 12); // light red
	std::cout << "ATTACK: " << h.attack << std::endl;
	SetConsoleTextAttribute(hConsole, 9); // light blue
	std::cout << "AGILITY: " << h.agility << std::endl;
	SetConsoleTextAttribute(hConsole, 14); // yellow
	std::cout << "LUCK: " << h.luck << std::endl;
	SetConsoleTextAttribute(hConsole, 15); // white
}

void Hero::setSkillPoints(Hero &h) {

}