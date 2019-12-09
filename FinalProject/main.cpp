/*******************************************************************************************
** Author: Edgar Hernandez
** Creation Date: 12/1/2019
** Description: This program contains an implementation of a sci-fi game based on the short
** story "The Last Question" by Isaac Asimov. The game contains several missions for the user
** to complete. The user travels through space and/or time to complete the game
********************************************************************************************/
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>
#include <memory>
#include "inputValidation.hpp"
#include "Game.hpp"
#include "menu.hpp"




int main()
{
	//Uses the current time to generate a random seed for each roll
	//Downcast as unsigned int to convert to 32-bit integer
	srand((unsigned int)time(NULL));

	menu();


	

	return 0;
}