#include "MontyHall.h"
#include "Probability.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


MontyHall::MontyHall()
{
}


MontyHall::~MontyHall()
{
}

void MontyHall::runSim()
{
	srand(time(NULL));

	int count;
	std::cout << "Choose how many simulations you want ( int <= 1,000,000) " << std::endl;
	std::cin >> count;

	auto Game = new Probability();

	Game->size = 3;

	for (int i = 0; i < count; i++)
	{
		Game->chooseCorrect();
		Game->chooseSelect();
		Game->chooseOther();

		Game->didSwitch= Game->switchChoice();
		Game->checkAns();
	}

	Game->chanceSwitch();
	float resultSwitch = Game->switchVictoryChance;
	Game->chanceKept();
	float resultKeep = Game->keptVictoryChance;


	std::cout << "Victory chance on Switching: " <<  resultSwitch << std::endl;
	std::cout << "Victory chance on Keeping: " << resultKeep << std::endl;

}
