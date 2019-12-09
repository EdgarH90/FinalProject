/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the specification for the futureX23 class.
** This class is derived from the base Space class.
*******************************************************************************/
#include "Space.hpp"
#ifndef FINALTIME_HPP
#define FINALTIME_HPP
#include <string>
#include <iostream>

class finalTime :
	public Space
{
protected:

public:
	finalTime();
	virtual ~finalTime();
	virtual std::string getStory();
};

#endif