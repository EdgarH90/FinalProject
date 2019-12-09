/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the specification for the futureX23 class.
** This class is derived from the base Space class and contains an override
** for the updateMap function.
*******************************************************************************/
#include "Space.hpp"
#ifndef HEATDEATH_HPP
#define HEATDEATH_HPP
#include <string>
#include <iostream>

class heatDeath :
	public Space
{
protected:

public:
	heatDeath();
	virtual ~heatDeath();
	virtual std::string getStory();
	virtual bool updateMap(int userMove);
};

#endif