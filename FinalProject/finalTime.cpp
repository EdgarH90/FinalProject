/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the finalTime class.
*******************************************************************************/
#include "finalTime.hpp"

/*********************************************************************
*					finalTime::finalTime()
* This is the default constructor that intializes the objects for the
* finalTime class.
*********************************************************************/
finalTime::finalTime()
{
	left = nullptr;
	right = nullptr;
	top = nullptr;
	bottom = nullptr;
	story = "finalTime.txt";
}

/*********************************************************************
*					finalTime::finalTime()
* This is the default destructor for the finalTime class.
*********************************************************************/
finalTime::~finalTime()
{

}


/*********************************************************************
*					finalTime::getStory()
* This function returns the string for the file containing the content
* of the story. It overrides the function of the parent class.
*********************************************************************/

std::string finalTime::getStory()
{
	return story;
}


