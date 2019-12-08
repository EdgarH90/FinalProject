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
	Space* left;
	Space* right;
	Space* top;
	Space* bottom;
	std::shared_ptr<Board> map;
	itemStorage storage;
	userMovement currentRotation;
	int userXpos = 0;
	int userYpos = 0;
	int numRows = 4;
	int numCols = 4;
	int playerStatus = 1;
	int itemCount = 0;
	bool gameOver = false;
public:
	virtual ~Space() = 0;
	virtual void placemapItems();
	virtual void setRight(Space* rightIn);
	virtual bool updateMap(int userMove);
	virtual void navigateMap();
	virtual bool getStatus();
	void showmap();
};

#endif.