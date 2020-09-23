#include "passenger.h"
#include <SDL.h>
#include <random>



int GenerateRandom(int range, int init) {
	
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(init, range);
	return distrib(gen);
}

Passenger::Passenger()
{
	// Initialize start and end floor 

	startFloor = GenerateRandom(FloorNum, 1);
	endFloor = GenerateRandom(FloorNum, 1);

	while (startFloor == endFloor) {
		std::random_device rd;  //Will be used to obtain a seed for the random number engine
		std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		std::uniform_int_distribution<> distrib(1, FloorNum);
		endFloor = distrib(gen);

		
		 

	}
}
