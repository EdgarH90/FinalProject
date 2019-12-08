/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the implementation of the black market class.
*******************************************************************************/
#include "blackMarket.hpp"


/*********************************************************************
*					blackMarket::blackMarket()
* This is the default constructor that intializes the objects for the
* blackMarket class.
*********************************************************************/
blackMarket::blackMarket()
{
	left = nullptr;
	right = nullptr;
	top = nullptr;
	bottom = nullptr;
	story = "police.txt";
}

/*********************************************************************
*					blackMarket::blackMarket()
* This is the default destructor that deletes the objects in memory
* in the blackMarket class.
*********************************************************************/
blackMarket::~blackMarket()
{
}
