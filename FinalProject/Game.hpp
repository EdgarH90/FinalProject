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
#include <memory>
#include <vector>
#include "itemQueue.hpp"
#include "Space.hpp"
#include "yeartwentyTwenty.hpp"

class Game
{
private:
	int roundWinner = 0;
	int damage = 0;
	int teamoneScore = 0;
	int teamtwoScore = 0;
	itemQueue storage;
public:
	Game() {};
	~Game() {};
	void getArt();
	void sectionBreak();
	void playGame();
};

#endif
