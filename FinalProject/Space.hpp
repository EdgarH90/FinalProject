/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the specification for the Space class.
*******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include <iostream>
#include "Board.hpp"

class Space
{
protected://MAKE PRIVATE
	Space* left;
	Space* right;
	Space* top;
	Space* bottom;
	std::shared_ptr<Board> map;
public:
	virtual ~Space() = 0;
	virtual void placeboardItems();
	void showmap();
};

#endif.