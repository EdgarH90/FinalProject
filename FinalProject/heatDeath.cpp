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
}

/*********************************************************************
*					heatDeath::heatDeath()
* This is the default destructor that deletes the objects in memory
* in the heatDeath class.
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


