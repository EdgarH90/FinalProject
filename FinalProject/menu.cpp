/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/7/2019
** Description:  This program contains the implementation for the menu function.
** The menu contains the Game object and instructions for the user to begin playing.
*******************************************************************************/
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "inputValidation.hpp"
#include "Game.hpp"
#include "itemStorage.hpp"

// The function takes in all user inputs and validates them
void menu()
{
	std::string errorMsg = "Please enter a valid integer";
	int status = 1;
	int userChoice = 0;

	// Source material for the story was obtained from
	// https://www.multivax.com/last_question.html
	std::cout << "*** Welcome to the game! ***" << std::endl;
	std::cout << "This game is based on the short story \"The Last Question \"\n"
		<< "by science fiction writer Isaac Asimov \n"
		<< "The goal of the game is to find the answer to the last \n"
		<< "question asked by man. You will travel through different points \n"
		<< "in time and complete several missions in order to find the answer. \n\n";

	std::cout << "Please select a number from the options below and press enter: " << std::endl;
	std::cout << "1. Start new game." << std::endl;
	std::cout << "2. Quit program." << std::endl;
	inputValidation(status, 1, 2);

	while (status != 2)
	{
		Game thelastQuestion;
		if (status == 1)
		{
			//Start the game
			thelastQuestion.playGame();
		}
		std::cout << "Would you like to play again? " << std::endl;
		std::cout << std::setw(10) << "1. Yes" << std::setw(10) << "2. No" << std::endl;
		inputValidation(userChoice, 1, 2);
		status = userChoice;
	}
	std::cout << "\n *********************** \n" << 
		"Game over. Thanks for playing!!" << std::endl;
	std::cout << " *********************** \n";
}

