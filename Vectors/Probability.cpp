/*
#include "Probability.h"
#include <stdlib.h>


Probability::Probability()
{
}


Probability::~Probability()
{
}

float Probability::chooseCorrect()
{
	ptr = &correct;
	return *ptr = rand() % size;
}

float Probability::chooseSelect()
{
	ptr = &selection;
	return *ptr = rand() % size;
}

bool Probability::switchChoice()
{
	ptr = &selection;
	bool change;
	change = rand() % 2;

	if (change)
	{
		if (*ptr != correct)
		{
			*ptr = correct;
		}
		else
		{
			*ptr = other;
		}
	}

	return change;
}

void Probability::checkAns()
{
	if (correct == selection)
	{
		if (didSwitch)
		{
			switchV++;
		}
		else
		{
			keptV++;
		}
	}
	else
	{
		if(didSwitch)
		{
			switchL++;
		}
		else
		{
			keptL++;
		}
	}
}

float Probability::chooseOther()
{
	ptr = &other;

	for (int i = 0; i < size; i++)
	{
		if (i != correct && i != selection)
		{
			return *ptr = i;
		}

	}

	return -1;
}

float Probability::chanceSwitch()
{
	fptr = &switchVictoryChance;
	float result = (switchV / (switchV + switchL));

	*fptr = result;
	return result;
}

float Probability::chanceKept()
{
	fptr = &keptVictoryChance;
	float result = (keptV / (keptV + keptL));

	*fptr = result;
	return result;
}
*/
