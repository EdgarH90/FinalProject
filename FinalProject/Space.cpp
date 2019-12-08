/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the Space class.
*******************************************************************************/
#include "Space.hpp"

//Pure virtual destructor
Space::~Space() {}


/*********************************************************************
*					Space::placemapItems()
* This function randomly places the items the user needs to collect.
*********************************************************************/
void Space::placemapItems()
{
	//Generate random x and y coordinates on the board
	for (int i = 0; i < 3; i++)
	{
		int xCoord = rand() % 3 + 1;
		int yCoord = rand() % 3 + 1;
		map->changeColor(xCoord, yCoord);
	}
}

/*********************************************************************
*					Space::showmap()
* This function prints the current state of the board and the ant's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

void Space::showmap()
{
	map->showBoard(userXpos, userYpos); //UPDATE
}


/*********************************************************************
*					Space::updateMap()
* This function updates the color of the board's tiles by using the
* structure pointer operator to access the Board object's member functions.
* The ant's rotation is set based on the current orientation in the enum
* antRotation object. The modulus operator is used to ensure the rotation loops
* correctly.
*********************************************************************/

bool Space::updateMap(int userMove)
{
	bool flag = false;

	if (map->getboardCoord(userXpos, userYpos) == ' ')
	{

		map->changeColor(userXpos, userYpos);
		currentRotation = static_cast<userMovement>(userMove); // Ensures enum value is not out of range
		navigateMap();
		return false;
	}
	if (map->getboardCoord(userXpos, userYpos) == '?')
	{
		std::cout << "You have collected an item. " << std::endl;
		itemCount++;
		map->resetTile(userXpos, userYpos);
		if (itemCount == 3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (map->getboardCoord(userXpos, userYpos) == '#')
	{
		std::cout << "You stepped into a radiation zone and died. \n"
			<< "GAME OVER \n";
		gameOver = true;
		return true;
	}
}

/*********************************************************************
*					Space::navigateMap()
* The user's movement is based on the currentRotation value set in the
* updateTile function. The x and y axes had to be swapped to ensure the
* movement was correct.
*********************************************************************/

void Space::navigateMap()
{
	if (currentRotation == N)
	{
		if ((userYpos - 1) < 0)
			userYpos = (numCols - 1);
		else
			userYpos--;
	}
	else if (currentRotation == E)
	{
		if ((userXpos - 1) < 0)
			userXpos = (numRows - 1);
		else
			userXpos--;
	}
	else if (currentRotation == S)
	{
		if ((userYpos + 1) > (numCols - 1))
			userYpos = 0;
		else
			userYpos++;
	}
	else
	{
		if ((userXpos + 1) > (numRows - 1))
			userXpos = 0;
		else
			userXpos++;
	}
}

/*********************************************************************
*					Space::showmap()
* This function prints the current state of the board and the ant's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

void Space::setRight(Space* rightIn)
{
	right = rightIn; //UPDATE
}

/*********************************************************************
*					Space::getStatus()
* This function prints the current state of the board and the ant's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

bool Space::getStatus()
{
	return gameOver; 
}