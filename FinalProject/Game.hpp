/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the specification for the Game class.
*******************************************************************************/
#ifndef PLAYGAME_HPP
#define PLAYGAME_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include "inputValidation.hpp"
#include "itemStorage.hpp"
#include "Space.hpp"
#include "yeartwentyTwenty.hpp"
#include "researchLab.hpp"
#include "blackMarket.hpp"
#include "skyline.hpp"
#include "futureX23.hpp"
#include "distFuture.hpp"
#include "unknownTime.hpp"
#include "heatDeath.hpp"
#include "finalTime.hpp"

class Game
{
public:
	std::shared_ptr<Space> year2020;
	std::shared_ptr<Space> drsLab;
	std::shared_ptr<Space> market;
	std::shared_ptr<Space> city;
	std::shared_ptr<Space> x23;
	std::shared_ptr<Space> distantFuture;
	std::shared_ptr<Space> unknown;
	std::shared_ptr<Space> finTime;
	std::shared_ptr<Space> heatTime;
	std::shared_ptr<Space> currentLocation; //Keeps track of the player's current location
	std::string fileOutput = ""; //String for the text file containing the story
	bool gameStatus = true;
	bool missionOver = true;
	int fuel = 25; //Keep track of fuel remaining
	int userChoice = 0;
	int userMovement = 0;
public:
	Game();
	~Game() {};
	void getStory(int fileNumber);
	void getStory(std::string inputFile);
	void sectionBreak();
	void playGame();
	void mission(std::shared_ptr<Space> spaceIn);

};

#endif
