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
	std::cout << "Okay, time to send you into the dungeon. Good luck hero!\n";
	std::cout << "Loading ";
	for (int i = 0; i < 5; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(750)); // SUSPENSE!
		std::cout << ".";
	}
}

