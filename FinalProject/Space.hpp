/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the specification for the Space class.
** It contains four pointers that are linked to different locations or places in
** time. It also contains the functions for the map manipulation and goal
** objectives.
*******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include <iostream>
#include <memory>
#include "Board.hpp"
#include "itemStorage.hpp"

// Enumerated data type is used to create the private member for the rotation
enum userMovement { N, E, S, W };


class Space
{
protected: 
	std::shared_ptr<Space> left;
	std::shared_ptr<Space> right;
	std::shared_ptr<Space> top;
	std::shared_ptr<Space> bottom;
	std::shared_ptr<Board> map; //Map for the in-game missions
	itemStorage storage; //Store the items needed for the missions
	userMovement currentRotation;
	int userXpos = 0; //Used by the map functions as coordinates
	int userYpos = 0; //Used by the map functions as coordinates
	int numRows = 4; //Used to set the map dimensions
	int numCols = 4; //Used to set the map dimensions
	int playerStatus = 1;
	int itemCount = 0; //Keeps track of the items
	int itemsNeeded = 3; //Items needed for the generic mission
	int fuel = 25; //Used as a method to track time left in mission
	std::string story = "";
	bool gameOver = true;
public:
	virtual ~Space() = 0;
	virtual void resetCoord();
	virtual void setRight(std::shared_ptr<Space> rightIn);
	virtual void setLeft(std::shared_ptr<Space> rightIn);
	virtual void setTop(std::shared_ptr<Space> rightIn);
	virtual void setBottom(std::shared_ptr<Space> rightIn);
	virtual std::shared_ptr<Space> getRight();
	virtual std::shared_ptr<Space> getLeft();
	virtual std::shared_ptr<Space> getTop();
	virtual std::shared_ptr<Space> getBottom();
	virtual bool updateMap(int userMove);
	virtual void navigateMap();
	virtual  std::string getStory();
	virtual bool getStatus();
	virtual int getFuel();
	virtual void storeItem(int value, int sizeLimit);
	virtual void showmap();
	virtual bool checkItems();
};
#endif