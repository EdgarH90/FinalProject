/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the Space class.
** It also contains the functions for the map manipulation, goal objectives, 
** and setting/getting the Space pointers. 
*******************************************************************************/
#include "Space.hpp"

//Pure virtual destructor
Space::~Space() {}


/*********************************************************************
*					Space::resetCoord()
* Reset the x and y coordinates for the map back to the origin on the
* map
*********************************************************************/
void Space::resetCoord()
{
	userXpos = 0;
	userYpos = 0;
}

/*********************************************************************
*					Space::showmap()
* This function prints the current state of the board and the user's position
* by using the structure pointer operator to pass the position to the
* Board object's showBoard function.
*********************************************************************/

void Space::showmap()
{
	map->showBoard(userXpos, userYpos); 
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
		gameOver = true; //Used to end game if the user failed
	}
	return flag; //Return the mission status
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
* This function takes in a shared Space pointer as a parameter and uses
* it to set the right Space pointer.
*********************************************************************/

void Space::setRight(std::shared_ptr<Space> rightIn)
{
	right = rightIn; 
}

/*********************************************************************
*					Space::setLeft()
* This function takes in a shared Space pointer as a parameter and uses
* it to set the left Space pointer.*********************************************************************/

void Space::setLeft(std::shared_ptr<Space> leftIn)
{
	left = leftIn; 
}

/*********************************************************************
*					Space::setTop()
* This function takes in a shared Space pointer as a parameter and uses
* it to set the top Space pointer.
*********************************************************************/

void Space::setTop(std::shared_ptr<Space> topIn)
{
	top = topIn;
}

/*********************************************************************
*					Space::setBottom()
* This function takes in a shared Space pointer as a parameter and uses
* it to set the bottom Space pointer.
*********************************************************************/

void Space::setBottom(std::shared_ptr<Space> bottomIn)
{
	bottom = bottomIn; 
}

/*********************************************************************
*					Space::getRight()
* This function returns the current right Space pointer.
*********************************************************************/

std::shared_ptr<Space> Space::getRight()
{
	return right;
}

/*********************************************************************
*					Space::getLeft()
* This function returns the current left Space pointer.
*********************************************************************/

std::shared_ptr<Space> Space::getLeft()
{
	return left; 
}

/*********************************************************************
*					Space::getTop()
* This function prints the current state of the board and the user's position
* This function returns the current right Space pointer.
*********************************************************************/

std::shared_ptr<Space> Space::getTop()
{
	return top; 
}

/*********************************************************************
*					Space::getBottom()
* This function prints the current state of the board and the user's position
* This function returns the current bottom Space pointer.
*********************************************************************/

std::shared_ptr<Space> Space::getBottom()
{
	return bottom; 
}


/*********************************************************************
*					Space::getStory()
* This function returns the filename of the current part of the story.
*********************************************************************/

std::string Space::getStory()
{
	return story;
}

/*********************************************************************
*					Space::getStatus()
* This function returns the current state of the game
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