/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the specification for the unknownTime class.
** This class is derived from the base Space class and contains an override
** for the updateMap function.
*******************************************************************************/
#include "Space.hpp"
#ifndef UNKNOWNTIME_HPP
#define UNKOWNTIME_HPP
#include <string>
#include <iostream>

class unknownTime :
	public Space
{
protected:

public:
	unknownTime();
	virtual ~unknownTime();
	virtual std::string getStory();
	virtual bool updateMap(int userMove);
};

#endif