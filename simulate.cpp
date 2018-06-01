#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>

#include <windows.h> // WinApi header
#include "menu.h"
#include "hero.h"
#include "simulate.h"

void Simulate::promptSimulation() {
	std::cout << "\n\n";
	std::cout << "Okay, time to send you into the dungeon. Are you ready to head out (y)es or (q)uit? : ";

	char dungeonReady = '/0';
	std::cin >> dungeonReady;
	switch (dungeonReady) {
	case 'y':
		std::cout << "Good luck Hero! I hope to see you at the bottom floor! I'll head to the elevators now.\n";
		for (int i = 0; i < 5; ++i) {
			std::this_thread::sleep_for(std::chrono::milliseconds(750)); // SUSPENSE!
			std::cout << " ... walking ... ";
		}
		break;

	case 'q':
		exit(0);
		break;
	default:
		std::cerr << "ERROR: Option not recognized\n";
	}
}

