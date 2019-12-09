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
* This is the default destructor for the class
*********************************************************************/
skyline::~skyline()
{

}

/*********************************************************************
*					skyline::navigateMap()
* The user's movement is based on the currentRotation value set in the
* updateTile function. This overrides the base class function as this
* object does not have a map.
*********************************************************************/

void skyline::navigateMap()
{

}

