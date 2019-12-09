/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the heatDeath class.
*******************************************************************************/
#include "heatDeath.hpp"

/*********************************************************************
*					heatDeath::heatDeath()
* This is the default constructor that intializes the objects for the
* heatDeath class.
*********************************************************************/
heatDeath::heatDeath()
{
	left = nullptr;
	right = nullptr;
	top = nullptr;
	bottom = nullptr;
	story = "heatDeath.txt";
	numRows = 6;
	numCols = 6;
	map = std::make_shared<Board>(6, 6);
	fuel = 50;
	itemsNeeded = 7;
}

/*********************************************************************
*					heatDeath::heatDeath()
* This is the default destructor for the class.
*********************************************************************/
heatDeath::~heatDeath()
{

}


/*********************************************************************
*					heatDeath::getStory()
* This function returns the string for the file containing the content
* of the story. It overrides the function of the parent class.
*********************************************************************/

std::string heatDeath::getStory()
{
	return story;
}

/*********************************************************************
*					heatDeath::updateMap()
* This function updates the color of the board's tiles by using the
* structure pointer operator to access the Board object's member functions.
* This function overrides the base class's function.
*********************************************************************/

bool heatDeath::updateMap(int userMove)
{
	bool flag = false;

	if (map->getboardCoord(userXpos, userYpos) == ' ')
	{

		map->changeColor(userXpos, userYpos, 5);
		currentRotation = static_cast<userMovement>(userMove); // Ensures enum value is not out of range
		navigateMap();
	}
	if (map->getboardCoord(userXpos, userYpos) == '1')
	{
		itemCount++;
		storeItem(1, itemsNeeded);
		std::cout << "You have collected " << itemCount << " of the 7 pools. " << std::endl;
		map->resetTile(userXpos, userYpos);
		if (checkItems()) //Check the storage container for items
		{
			gameOver = false;
			flag = true;
		}
	}
	else if (map->getboardCoord(userXpos, userYpos) == '?')
	{
		std::cout << "Your data was corrupted. \n";
		flag = true;
	}
	return flag;
}