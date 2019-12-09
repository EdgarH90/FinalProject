/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the specification for the distFuture class.
*******************************************************************************/
#include "Space.hpp"
#ifndef DISTFUTURE_HPP
#define DISTFUTURE_HPP
#include <string>
#include <iostream>

class distFuture :
	public Space
{
protected:

public:
	distFuture();
	virtual ~distFuture();
	virtual std::string getStory();
	virtual bool updateMap(int userMove);
};

#endif