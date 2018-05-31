#pragma once
#include <string>

class Enemy {
	int attack;
	int health;
};

class Slime : public Enemy {
	std::string name;
};

class Goblin : public Enemy {
	std::string name;
};