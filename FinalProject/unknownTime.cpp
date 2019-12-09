/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the unknownTime class.
*******************************************************************************/
#include "unknownTime.hpp"

/*********************************************************************
*					unknownTime::unknownTime()
* This is the default constructor that intializes the objects for the
* unknownTime class.
*********************************************************************/
unknownTime::unknownTime()
{
	left = nullptr;
	right = nullptr;
	top = nullptr;
	bottom = nullptr;
	story = "unknownTime.txt";
	map = std::make_shared<Board>(4, 4);
	fuel = 30;
	itemsNeeded = 6;
}

/*********************************************************************
*					unknownTime::unknownTime()
* This is the default destructor that deletes the objects in memory
* in the unknownTime class.
*********************************************************************/
unknownTime::~unknownTime()
{

}


/*********************************************************************
*					unknownTime::getStory()
* This function returns the string for the file containing the content
* of the story. It overrides the function of the parent class.
*********************************************************************/

std::string unknownTime::getStory()
{
	return story;
}

/*********************************************************************
*					unknownTime::updateMap()
* This function updates the color of the board's tiles by using the
* structure pointer operator to access the Board object's member functions.
* This function overrides the base class's function.
*********************************************************************/

bool unknownTime::updateMap(int userMove)
{
	bool flag = false;

	if (map->getboardCoord(userXpos, userYpos) == ' ')
	{

		map->changeColor(userXpos, userYpos, 4);
		currentRotation = static_cast<userMovement>(userMove); // Ensures enum value is not out of range
		navigateMap();
	}
	if (map->getboardCoord(userXpos, userYpos) == '~')
	{
		itemCount++;
		storeItem(1, itemsNeeded);
		std::cout << "You have collected " << itemCount << " of the galaxies' energy. " << std::endl;
		map->resetTile(userXpos, userYpos);
		if (checkItems()) //Check the storage container for items
		{
			gameOver = false;
			std::cout << "returning flag \n";
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
