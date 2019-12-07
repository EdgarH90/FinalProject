/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the yeartwentyTwenty class.
*******************************************************************************/
#include "yeartwentyTwenty.hpp"

/*********************************************************************
*					yeartwentyTwenty::yeartwentyTwenty()
* This is the default constructor that intializes the objects for the
* yeartwentyTwenty class.
*********************************************************************/
yeartwentyTwenty::yeartwentyTwenty()
{
	left = nullptr;
	right = nullptr;
	top = nullptr;
	bottom = nullptr;
	map = std::make_shared<Board>(4,4);
}

/*********************************************************************
*					yeartwentyTwenty::yeartwentyTwenty()
* This is the default destructor that deletes the objects in memory
* in the yeartwentyTwenty class.
*********************************************************************/
yeartwentyTwenty::~yeartwentyTwenty()
{

}