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


