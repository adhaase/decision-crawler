#pragma once
#include <vector>

struct Tools {
public:
	int name; // tool name
};

struct Weapon: public Tools { // a weapon is tool (inherits from parent class Tools)
	int attack;
	int durability;
};

class Hero {
private:
	int vitality;
	int attack;
	int agility;
	int luck;
	std::vector<Tools> backpack;
public:
	Hero(); // hero ctor -- initalizes hero stats and backpack
	void setSkillPoints(Hero &h);
	//individual value get/set print functions
	void setvitality(int vitality, Hero &h);
	void setAttack(int attack, Hero &h);
	void setAgility(int agility, Hero &h);
	void setLuck(int luck, Hero &h);

	void printvitality(Hero &h);
	void printAttack(Hero &h);
	void printAgility(Hero &h);
	void printLuck(Hero &h);

	void printHeroStats(Hero &h);
};