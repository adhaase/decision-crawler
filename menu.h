#pragma once
#include "hero.h"

class UI {
public:
	void printHeader();
	void printIntro();
};

class Distribution {
public:
	void distributeSkillPoints(Hero &h);
	void heroStatsConversation(Hero &h, Distribution &d);
};