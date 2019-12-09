/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the specification for the futureX23 class.
** This class is derived from the base Space class and contains an override
** for the updateMap function.
*******************************************************************************/
#include "Space.hpp"
#ifndef FUTUREX23_HPP
#define FUTUREX23_HPP
#include <string>
#include <iostream>

class futureX23 :
	public Space
{
protected:

public:
	futureX23();
	virtual ~futureX23();
	virtual std::string getStory();
	virtual bool updateMap(int userMove);
};

#endif