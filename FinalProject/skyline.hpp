/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the specification for the skyline class.
*******************************************************************************/
#include "Space.hpp"
#ifndef	SKYLINE_HPP
#define SKYLINE_HPP
#include <string>
#include <iostream>

class skyline :
	public Space
{
protected:

public:
	skyline();
	virtual ~skyline();
	virtual void navigateMap();
};

#endif