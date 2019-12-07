/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the implementation for the Game class.
** 
*******************************************************************************/
#include "Game.hpp"


/*********************************************************************
*					Game::getArt()
* This function takes in an integer as a paramater and uses it to determine
* which file's contents to return.
*********************************************************************/
void Game::getArt()
{
	std::ifstream fileIn("title_art.txt");
	std::string output = "";

	if (fileIn)
	{
		while (fileIn.good())
		{
			//Use placeholder for each line in file
			std::string temp;
			getline(fileIn, temp, '\n');
			//Add a newline character to keep output aligned
			temp += "\n";

			//Add line with extra newline character
			output += temp;
		}
		std::cout << output;
	}
	else
	{
		std::cout << "File could not be openend.";
	}
}

/*********************************************************************
*					Game::playGame()
* This function contains the implementation for the gameplay
*********************************************************************/

void Game::playGame()
{
	yeartwentyTwenty year2020;
	//Output the tile of the game
	getArt();
	sectionBreak();

	std::cout << "The last question was asked for the first time, \n"
		<< "on May 21, 2025, at a time when humanity \n"
		<< "first stepped into the light.... \n";

	sectionBreak();

	std::cout << "The year is 2020. Famed astrophysicist Carl Feynman \n"
		<< "has been tasked with collecting the uranium, deuterium, and tritium \n"
		<< "required for nuclear fusion. His goal is to create the Univac, \n"
		<< "the most powerful supercomputer humanity has ever seen, in the \n"
		<< "hopes of finding an answer to the world's energy crisis. \n";

	std::cout << "\nYour mission is to help Dr. Feynman collect the materials required" << std::endl;

	sectionBreak();

	std::cout << "Gather one deposit of each of the three elements necessary \n"
		<<"by moving around the map.\nWARNING: AVOID RADIATION ZONES (white squares)! \n";

	sectionBreak();

	year2020.placeboardItems();
	year2020.showmap();

}

/*********************************************************************
*					Game::sectionBreak()
* This function outputs a line of asterisks to help break up the flow
* of the narrative.
*********************************************************************/

void Game::sectionBreak()
{
	std::string sectionBreak = "\n*************************************************** \n";
	std::cout << sectionBreak;
}