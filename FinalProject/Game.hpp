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

class Game
{
protected:
	std::shared_ptr<Space> year2020;
	std::shared_ptr<Space> drsLab;
	std::shared_ptr<Space> market;
	std::shared_ptr<Space> city;
	std::shared_ptr<Space> currentLocation; //Keeps track of the player's current location
	itemStorage storage;
	std::string fileOutput = ""; //String for the text file containing the story
	bool gameStatus = true;
public:
	Game();
	~Game() {};
	void getStory(int fileNumber);
	void getStory(std::string inputFile);
	void sectionBreak();
	void playGame();
};

#endif
