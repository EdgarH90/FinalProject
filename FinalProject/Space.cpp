/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the Space class.
*******************************************************************************/
#include "Space.hpp"

//Pure virtual destructor
Space::~Space() {}


/*********************************************************************
*					Space::placeboardItems()
* This function randomly places the items the user needs to collect.
*********************************************************************/
void Space::placeboardItems()
{
	//Generate random x and y coordinates on the board
	int xCoord = rand() % 3 + 1;
	int yCoord = rand() % 3 + 1;
	map->changeColor(xCoord, yCoord);
}

/*********************************************************************
*					Space::showmap()
* This function prints the current state of the board and the ant's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

void Space::showmap()
{
	map->showBoard(1, 1); //UPDATE
}