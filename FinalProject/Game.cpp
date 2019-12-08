/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the implementation for the Game class.
** 
*******************************************************************************/
#include "Game.hpp"



Game::Game()
{
	year2020 = std::make_shared<yeartwentyTwenty>();
	drsLab = std::make_shared<researchLab>();
	market = std::make_shared<blackMarket>();
	city = std::make_shared<skyline>();	
	//Set the pointers to the appropriate spaces
	year2020->setRight(drsLab);
	year2020->setLeft(market);
	drsLab->setLeft(city);
	city->setRight(drsLab);
}
/*********************************************************************
*					Game::getStory()
* This function takes in an integer as a paramater and uses it to determine
* which file's contents to return.
*********************************************************************/
void Game::getStory(int filenumber)
{
	std::string files[2] = { "title_art.txt", "feynmansLab.txt" };
	std::ifstream fileIn(files[filenumber]);
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
		std::cout << "File could not be opened.";
	}
}

/*********************************************************************
*					Game::getStory()
* This function overrides the getStory() function. It takes in a string
* as a paramater and uses it to determine which file's contents to return.
*********************************************************************/
void Game::getStory(std::string inputFile)
{
	std::ifstream fileIn(inputFile);
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
		std::cout << "File could not be opened.";
	}
}

/*********************************************************************
*					Game::playGame()
* This function contains the implementation for the gameplay
*********************************************************************/

void Game::playGame()
{
	//Set the right pointer to Dr. Feynman's Lab
	//year2020->setRight(drsLab); FIX
	//year2020->setLeft(market); FIX
	//drsLab->setTop(machine);
	//drsLab->setBottom()
	int userChoice = 0;
	int userMovement = 0;
	//Output the title of the game
	getStory(0);
	std::cout << "\r";
	sectionBreak();

	std::cout << "The last question was asked for the first time,\n"
		<< "half in jest, on May 21, 2030, at a time when humanity \n"
		<< "first stepped into the light.... \n";

	sectionBreak();

	std::cout << "The year is 2020. Famed astrophysicist Carl Feynman \n"
		<< "has been tasked with collecting the uranium, deuterium, and tritium \n"
		<< "required for nuclear fusion. His goal is to create the Univac, \n"
		<< "the most powerful supercomputer humanity has ever seen, in the \n"
		<< "hopes of finding an answer to the world's energy crisis. \n";

	std::cout << "\nYour mission is to help Dr. Feynman collect the materials required \n"
		<< "Do you accept?" << std::endl;
	std::cout << "1. Yes, I'll step into the collection vehicle. \n"
		<< "2. No, I don't want to find the answer. \n";
	inputValidation(userChoice, 1, 2);
	sectionBreak();

	if (userChoice == 1)
	{
		std::cout << "Gather one deposit of each of the three elements necessary \n"
			<< "by moving around the map.\nWARNING: AVOID RADIATION ZONES (# squares)! \n"
			<< "Use the following keys to navigate: \n"
			<< "0 - Left \n"
			<< "1 - Up \n"
			<< "2 - Right \n"
			<< "3 - Down \n";

		sectionBreak();

		//Set the status of the current mission
		bool missionOver = false;
		for (int i = 0; i <= 25; i++)
		{
			while (!missionOver)
			{
				year2020->showmap();
				inputValidation(userMovement, 0, 3);
				missionOver = year2020->updateMap(userMovement);
			}
			gameStatus = year2020->getStatus();
		}
		while (!gameStatus)
		{
			std::cout << "Well done! What would you like to do next? \n";
			std::cout << "1. Take the materials to Dr. Feynman's Lab. \n"
				<< "2. Sell the materials on the black market. \n";
			inputValidation(userChoice, 1, 2);
			sectionBreak();
			if (userChoice == 1)
			{
				currentLocation = year2020->getRight();
				fileOutput = currentLocation->getStory();
				getStory(1); //Output story from lab
				std::cout << "\n1. Ask the Univac a question \n"
					<< "2. Leave Dr. Feynman's office. \n";
				inputValidation(userChoice, 1, 2);
				while (userChoice != 1 && !gameStatus)
				{
					currentLocation = currentLocation->getLeft(); //Set location to city
					fileOutput = currentLocation->getStory();
					getStory(fileOutput);
					std::cout << "\n1. Return to the lab and ask the Univac a question \n"
						<< "2. Continue on your way \n";
					inputValidation(userChoice, 1, 2);
					if (userChoice ==2)
					{
						gameStatus = false;
					}
				}

				currentLocation = currentLocation->getRight(); //Set location back to lab
				fileOutput = currentLocation->getStory();
				getStory(fileOutput);

				sectionBreak();

			}
			else
			{
				fileOutput = year2020->getLeft()->getStory();
				getStory(fileOutput);
				gameStatus = year2020->getLeft()->getStatus();
			}
		}
	}
	std::cout << "GAME OVER" << std::endl;


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