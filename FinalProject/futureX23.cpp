/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the futureX23 class.
*******************************************************************************/
#include "futureX23.hpp"

/*********************************************************************
*					futureX23::futureX23()
* This is the default constructor that intializes the objects for the
* futureX23 class.
*********************************************************************/
futureX23::futureX23()
{
	left = nullptr;
	right = nullptr;
	top = nullptr;
	bottom = nullptr;
	story = "future.txt";
	map = std::make_shared<Board>(4, 4);
	fuel = 30;
	itemsNeeded = 4;
}

/*********************************************************************
*					futureX23::futureX23()
* This is the default destructor for the class
*********************************************************************/
futureX23::~futureX23()
{

}


/*********************************************************************
*					futureX23::getStory()
* This function returns the string for the file containing the content
* of the story. It overrides the function of the parent class.
*********************************************************************/

std::string futureX23::getStory()
{
	return story;
}

/*********************************************************************
*					futureX23::updateMap()
* This function updates the color of the board's tiles by using the
* structure pointer operator to access the Board object's member functions.
* This function overrides the base class's function.
*********************************************************************/

bool futureX23::updateMap(int userMove)
{
	bool flag = false;

	if (map->getboardCoord(userXpos, userYpos) == ' ')
	{

		map->changeColor(userXpos, userYpos, 2);
		currentRotation = static_cast<userMovement>(userMove); // Ensures enum value is not out of range
		navigateMap();
	}
	if (map->getboardCoord(userXpos, userYpos) == '?')
	{
		itemCount++;
		storeItem(1, itemsNeeded);
		std::cout << "You have collected " << itemCount << " of the 4 planets' energies. " << std::endl;
		map->resetTile(userXpos, userYpos);
		if (checkItems()) //Check the storage container for items
		{
			gameOver = false;
			flag = true;
		}
	}
	else if (map->getboardCoord(userXpos, userYpos) == 'O')
	{
		std::cout << "You hit an asteroid and died. \n";
		flag = true;
	}
	return flag;
}

