/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the specification for the Space class.
*******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include <iostream>
#include "Board.hpp"
#include "itemStorage.hpp"

// Enumerated data type is used to create the private member for the rotation
enum userMovement { N, E, S, W };

//This struct represents each node in space
//struct SpaceNode
//{
//	userMovement currentRotation;
//	SpaceNode* next;
//	SpaceNode* prev;
//};

class Space
{
protected://MAKE PRIVATE
	std::shared_ptr<Space> left;
	std::shared_ptr<Space> right;
	std::shared_ptr<Space> top;
	std::shared_ptr<Space> bottom;
	std::shared_ptr<Board> map;
	itemStorage storage;
	userMovement currentRotation;
	int userXpos = 0;
	int userYpos = 0;
	int numRows = 4;
	int numCols = 4;
	int playerStatus = 1;
	int itemCount = 0;
	std::string story = "";
	bool gameOver = true;
public:
	virtual ~Space() = 0;
	virtual void placemapItems();
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
	void showmap();
};

#endif.