/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the skyline class.
*******************************************************************************/
#include "skyline.hpp"

/*********************************************************************
*					skyline::skyline()
* This is the default constructor that intializes the objects for the
* skyline class.
*********************************************************************/
skyline::skyline()
{
	left = nullptr;
	right = nullptr;
	top = nullptr;
	bottom = nullptr;
	story = "skyline.txt";
}

/*********************************************************************
*					skyline::skyline()
* This is the default destructor that deletes the objects in memory
* in the skyline class.
*********************************************************************/
skyline::~skyline()
{

}

/*********************************************************************
*					skyline::navigateMap()
* The user's movement is based on the currentRotation value set in the
* updateTile function. The x and y axes had to be swapped to ensure the
* movement was correct.
*********************************************************************/

void skyline::navigateMap()
{

}

