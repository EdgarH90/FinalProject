/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the Space class.
*******************************************************************************/
#include "Space.hpp"

//Pure virtual destructor
Space::~Space() {}


/*********************************************************************
*					Space::resetCoord()
* Reset the x and y coordinates for the map.
*********************************************************************/
void Space::resetCoord()
{
	userXpos = 0;
	userYpos = 0;
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
*********************************************************************/

bool Space::updateMap(int userMove)
{
	bool flag = false;

	if (map->getboardCoord(userXpos, userYpos) == ' ')
	{

		map->changeColor(userXpos, userYpos, 1);
		currentRotation = static_cast<userMovement>(userMove); // Ensures enum value is not out of range
		navigateMap();
	}
	if (map->getboardCoord(userXpos, userYpos) == 'D')
	{
		itemCount++;
		storeItem(1, itemsNeeded);
		std::cout << "You have collected " << itemCount <<" of the 3 nuclear items. " << std::endl;
		map->resetTile(userXpos, userYpos);
		if (checkItems()) //Check the storage container for items
		{
			gameOver = false;
			flag = true;
		}
	}
	else if (map->getboardCoord(userXpos, userYpos) == '#')
	{
		std::cout << "You stepped into a radiation zone and died. \n";
		flag = true;
		gameOver = true;
	}
	return flag;
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
*					Space::setRight()
* This function prints the current state of the board and the ant's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

void Space::setRight(std::shared_ptr<Space> rightIn)
{
	right = rightIn; //UPDATE
}

/*********************************************************************
*					Space::setLeft()
* This function prints the current state of the board and the ant's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

void Space::setLeft(std::shared_ptr<Space> leftIn)
{
	left = leftIn; //UPDATE
}

/*********************************************************************
*					Space::setTop()
* This function prints the current state of the board and the ant's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

void Space::setTop(std::shared_ptr<Space> topIn)
{
	top = topIn; //UPDATE
}

/*********************************************************************
*					Space::setDown()
* This function prints the current state of the board and the ant's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

void Space::setBottom(std::shared_ptr<Space> bottomIn)
{
	bottom = bottomIn; //UPDATE
}

/*********************************************************************
*					Space::setRight()
* This function prints the current state of the board and the ant's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

std::shared_ptr<Space> Space::getRight()
{
	return right;
}

/*********************************************************************
*					Space::setLeft()
* This function prints the current state of the board and the ant's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

std::shared_ptr<Space> Space::getLeft()
{
	return left; //UPDATE
}

/*********************************************************************
*					Space::setTop()
* This function prints the current state of the board and the ant's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

std::shared_ptr<Space> Space::getTop()
{
	return top; //UPDATE
}

/*********************************************************************
*					Space::setDown()
* This function prints the current state of the board and the ant's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

std::shared_ptr<Space> Space::getBottom()
{
	return bottom; //UPDATE
}


/*********************************************************************
*					Space::getStory()
* This function prints the current state of the space
*********************************************************************/

std::string Space::getStory()
{
	return story;
}

/*********************************************************************
*					Space::getStatus()
* This function prints the current state of the space
*********************************************************************/

bool Space::getStatus()
{
	return gameOver; 
}

/*********************************************************************
*					Space::getFuel()
* This function returns the fuel amount for the space
*********************************************************************/

int Space::getFuel()
{
	return fuel;
}

/*********************************************************************
*					Space::storeItem()
* This function stores an item in the container. It takes in two ints
* as parameters. The function checks if the container is full or empty
* before storing.
*********************************************************************/

void Space::storeItem(int value, int sizeLimit)
{
	storage.addBack(value, sizeLimit);
}

/*********************************************************************
*					Space::checkItems()
* This function checks to see if all items have been collected. 
* by comparing the values in storage to the number of items needed.
*********************************************************************/

bool Space::checkItems()
{
	if (storage.getValues() == itemsNeeded)
	{
		return true;
	}
	else
	{
		return false;
	}
}