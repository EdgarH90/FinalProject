/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the distFuture class.
*******************************************************************************/
#include "distFuture.hpp"

/*********************************************************************
*					distFuture::distFuture()
* This is the default constructor that intializes the objects for the
* distFuture class.
*********************************************************************/
distFuture::distFuture()
{
	left = nullptr;
	right = nullptr;
	top = nullptr;
	bottom = nullptr;
	story = "distFuture.txt";
	map = std::make_shared<Board>(4, 4);
	fuel = 30;
	itemsNeeded = 5;
}

/*********************************************************************
*					distFuture::distFuture()
* This is the default destructor for the class
*********************************************************************/
distFuture::~distFuture()
{

}


/*********************************************************************
*					distFuture::getStory()
* This function returns the string for the file containing the content
* of the story. It overrides the function of the parent class.
*********************************************************************/

std::string distFuture::getStory()
{
	return story;
}

/*********************************************************************
*					distFuture::updateMap()
* This function updates the color of the board's tiles by using the
* structure pointer operator to access the Board object's member functions.
* This function overrides the base class's function.
*********************************************************************/

bool distFuture::updateMap(int userMove)
{
	bool flag = false;

	if (map->getboardCoord(userXpos, userYpos) == ' ')
	{

		map->changeColor(userXpos, userYpos, 3);
		currentRotation = static_cast<userMovement>(userMove); // Ensures enum value is not out of range
		navigateMap();
	}
	if (map->getboardCoord(userXpos, userYpos) == 'S')
	{
		itemCount++;
		storeItem(1, itemsNeeded);
		std::cout << "You have collected " << itemCount << " of the 5 stars' energies. " << std::endl;
		map->resetTile(userXpos, userYpos);
		if (checkItems()) //Check the storage container for items
		{
			gameOver = false;
			flag = true;
		}
	}
	else if (map->getboardCoord(userXpos, userYpos) == 'O')
	{
		std::cout << "You were sucked into a black hole. \n";
		flag = true;
	}
	return flag;
}
