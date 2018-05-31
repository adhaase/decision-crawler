#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#include "menu.h"
#include "simulate.h"
#include "hero.h"
#include "enemy.h"

int main(int argc, char *argv[]) {

	UI ui;
	ui.printHeader();
	ui.printIntro();

	Hero h;
	Distribution d;
	d.heroStatsConversation(h, d);

	Simulate s;
	s.promptSimulation();

	system("pause");
	return 0;
}