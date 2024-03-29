/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the implementation for the Game class.
** This class contains all of the space objects and general gameplay functions.
*******************************************************************************/
#include "Game.hpp"



/*********************************************************************
*					Game::getStory()
* This is the default constructor for the game. It initializes all
* of the pointers for the space and sets the nodes. The Space classes
* are created with all four space pointers set to null.
*********************************************************************/
Game::Game()
{
	year2020 = std::make_shared<yeartwentyTwenty>();
	drsLab = std::make_shared<researchLab>();
	market = std::make_shared<blackMarket>();
	city = std::make_shared<skyline>();
	x23 = std::make_shared<futureX23>();
	distantFuture = std::make_shared<distFuture>();
	unknown = std::make_shared<unknownTime>();
	finTime = std::make_shared<finalTime>();
	heatTime = std::make_shared<heatDeath>();

	//Set the pointers to the appropriate spaces
	year2020->setRight(drsLab);
	year2020->setLeft(market);
	drsLab->setLeft(city);
	city->setRight(drsLab);
	drsLab->setRight(x23);
	x23->setTop(distantFuture);
	distantFuture->setRight(unknown);
	unknown->setRight(finTime);
	finTime->setLeft(heatTime);
	finTime->setRight(heatTime);
}
/*********************************************************************
*					Game::getStory()
* This function takes in an integer as a paramater and uses it to determine
* which file's contents to return. All original files were obtained 
* or modified from the following source:
* https://www.asciiart.eu/
*********************************************************************/
void Game::getStory(int filenumber)
{
	std::string files[3] = { "title_art.txt", "feynmansLab.txt", "final_art.txt" };
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
*					Game::gameMission()
* This function takes in a shared Space pointer as a parameter. It 
* then uses the pointer to call the appropriate class functions.
*********************************************************************/

void Game::mission(std::shared_ptr<Space> spaceIn)
{
	//Set the status of the current mission
	missionOver = false;

	//Reset the user coordinates on the map and update fuel
	fuel = spaceIn->getFuel();
	spaceIn->resetCoord(); 
	for (int i = 0; i <= fuel; i++)
	{
		while (!missionOver && fuel != 0)
		{
			spaceIn->showmap();
			std::cout << "Energy remaining: " << fuel << std::endl;
			inputValidation(userMovement, 0, 3);
			missionOver = spaceIn->updateMap(userMovement);
			fuel--;
		}
	}
	gameStatus = spaceIn->getStatus();
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

	//Output the title of the game
	getStory(0);
	std::cout << "\r";

	sectionBreak(); //Print out dividers to help flow of story

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

	//Take the user to the first mission
	if (userChoice == 1)
	{
		currentLocation = year2020;
		std::cout << "Gather one deposit (D) of each of the three elements necessary \n"
			<< "by moving around the map.\nWARNING: \n"
			<<"AVOID RADIATION ZONES (# squares)! \n"
			<< "DO NOT RUN OUT OF ENERGY! \n"
			<< "Use the following keys to navigate: \n"
			<< "0 - Left \n"
			<< "1 - Up \n"
			<< "2 - Right \n"
			<< "3 - Down \n";

		sectionBreak();
		mission(currentLocation);

		sectionBreak();

		while (!gameStatus)
		{
			std::cout << "Well done! What would you like to do next? \n";
			std::cout << "1. Take the materials to Dr. Feynman's Lab. \n"
				<< "2. Sell the materials on the black market. \n";
			inputValidation(userChoice, 1, 2);
			sectionBreak();
			if (userChoice == 1)
			{
				//Set the location to Dr. Feynman's lab
				currentLocation = year2020->getRight();
				fileOutput = currentLocation->getStory();
				getStory(1); //Output story from lab
				std::cout << "\n1. Ask the Univac the question \n"
					<< "2. Leave Dr. Feynman's office. \n";
				inputValidation(userChoice, 1, 2);

				//Loop until the user decides to return or quit
				while (userChoice != 1 && !gameStatus)
				{
					currentLocation = currentLocation->getLeft(); //Set location to city
					fileOutput = currentLocation->getStory();
					getStory(fileOutput);
					std::cout << "\n1. Return to the lab and ask the Univac a question \n";
					inputValidation(userChoice, 1, 1);
					if (userChoice ==1)
					{
						gameStatus = false;
					}
				}
				//Reset location back to lab if user selected the city
				if (currentLocation != drsLab)
				{
					currentLocation = currentLocation->getRight();
				}

				//Ask the Univac the question
				fileOutput = currentLocation->getStory();
				getStory(fileOutput);
				sectionBreak();

				//Go forward in time to reach planet X23
				std::cout << "Thousands of years later... \n";
				currentLocation = currentLocation->getRight();
				std::cout << "\nGather the energy of four planets (?) required for hypertravel to X23. \n"
					<< "by moving around the map.\nWARNING: \n"
					<< "AVOID RADIATION ZONES (O squares)! \n"
					<< "DO NOT RUN OUT OF ENERGY! \n"
					<< "0 - Left \n"
					<< "1 - Up \n"
					<< "2 - Right \n"
					<< "3 - Down \n";
				mission(currentLocation);

				sectionBreak();

				//Continue the story if the mission is successful
				if (!gameStatus)
				{
					fileOutput = currentLocation->getStory();
					getStory(fileOutput);

					sectionBreak();

					std::cout << "\n1. Continue your quest. \n"
						<< "2. Quit \n";
					inputValidation(userChoice, 1, 2);
					if (userChoice == 1)
					{
						gameStatus = false;
					}

					if (!gameStatus)
					{
						//Set current location to the distant future
						sectionBreak();
						currentLocation = currentLocation->getTop();
						std::cout << "Gather the energy (S) from five stars \n"
							<< "by moving around the map.\nWARNING: \n"
							<< "AVOID BLACK HOLES ('0' squares)! \n"
							<< "DO NOT RUN OUT OF ENERGY! \n"
							<< "Use the following keys to navigate: \n"
							<< "0 - Left \n"
							<< "1 - Up \n"
							<< "2 - Right \n"
							<< "3 - Down \n";
						mission(currentLocation);
						if (!gameStatus)
						{
							std::cout << "TEST POINT" << std::endl;
							sectionBreak();
							fileOutput = currentLocation->getStory();
							getStory(fileOutput);
							sectionBreak();
						}
					}

					if (!gameStatus)
					{
						std::cout << "\n1. Continue your quest. \n"
							<< "2. Quit \n";
						inputValidation(userChoice, 1, 2);
						if (userChoice == 1)
						{
							gameStatus = false;
						}
					}


					if (!gameStatus)
					{
						//Set current location to unknown time
						currentLocation = currentLocation->getRight();
						sectionBreak();
						std::cout << "Gather the energy (~) from six galaxies \n"
							<< "by moving around the map.\nWARNING: \n"
							<< "AVOID BLACK HOLES ('0' squares)! \n"
							<< "DO NOT RUN OUT OF ENERGY! \n"
							<< "Use the following keys to navigate: \n"
							<< "0 - Left \n"
							<< "1 - Up \n"
							<< "2 - Right \n"
							<< "3 - Down \n";
						mission(currentLocation);
						fileOutput = currentLocation->getStory();
						getStory(fileOutput);
						sectionBreak();
					}

					if (!gameStatus)
					{
						std::cout << "\n1. Travel to the time of Man. \n"
							<< "2. Quit \n";
						inputValidation(userChoice, 1, 2);
						if (userChoice == 1)
						{
							gameStatus = false;
						}
					}

					sectionBreak();

					if (!gameStatus)
					{
						//Set current location to man's final time
						sectionBreak();
						currentLocation = currentLocation->getRight();
						fileOutput = currentLocation->getStory();
						getStory(fileOutput);

						sectionBreak();
					}

					if (!gameStatus)
					{
						std::cout << "\n1. The Final Chapter. \n"
							<< "2. Quit \n";
						inputValidation(userChoice, 1, 2);
						if (userChoice == 1)
						{
							gameStatus = false;
						}
						sectionBreak();
					}
					if (!gameStatus)
					{
						//Set current location to death of universe
						currentLocation = currentLocation->getRight();
						fileOutput = currentLocation->getStory();
						getStory(fileOutput);
						sectionBreak();

						std::cout << "Gather 7 dark matter data pools (1) \n"
							<< "by moving around the map.\nWARNING: \n"
							<< "AVOID CORRUPTED DATA ('?' squares)! \n"
							<< "DO NOT RUN OUT OF ENERGY! \n"
							<< "Use the following keys to navigate: \n"
							<< "0 - Left \n"
							<< "1 - Up \n"
							<< "2 - Right \n"
							<< "3 - Down \n";
						mission(currentLocation);
						sectionBreak();
						
						if (!gameStatus)
						{
							getStory(2);
							sectionBreak();
							std::cout << "CONGRATULATIONS, YOU HAVE WON!" << std::endl;
						}
					}
					gameStatus = true;
				}
			}
			else
			{
				fileOutput = year2020->getLeft()->getStory();
				getStory(fileOutput);
				gameStatus = year2020->getLeft()->getStatus();
			}
		}
	}
}

/*********************************************************************
*					Game::sectionBreak()
* This function outputs a line of asterisks to help break up the flow
* of the narrative.
*********************************************************************/

void Game::sectionBreak()
{
	std::string sectionBreak = "\n\n*************************************************** \n\n";
	std::cout << sectionBreak;
}