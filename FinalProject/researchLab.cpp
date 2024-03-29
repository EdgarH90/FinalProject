/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the researchLab class.
*******************************************************************************/
#include "researchLab.hpp"

/*********************************************************************
*					researchLab::researchLab()
* This is the default constructor that intializes the objects for the
* researchLab class.
*********************************************************************/
researchLab::researchLab()
{
	left = nullptr;
	right = nullptr;
	top = nullptr;
	bottom = nullptr;
	story = "askQ.txt";
}

/*********************************************************************
*					researchLab::researchLab()
* This is the default destructor that deletes the objects in memory
* in the researchLab class.
*********************************************************************/
researchLab::~researchLab()
{

}

/*********************************************************************
*					researchLab::navigateMap()
* The user's movement is based on the currentRotation value set in the
* updateTile function. The x and y axes had to be swapped to ensure the
* movement was correct.
*********************************************************************/

void researchLab::navigateMap()
{

}


/*********************************************************************
*					researchLab::getStory()
* This function returns the string for the file containing the content
* of the story. It overrides the function of the parent class.
*********************************************************************/

std::string researchLab::getStory()
{
	gameOver = true;
	return story;
}

