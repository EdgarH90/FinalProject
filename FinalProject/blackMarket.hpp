/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the specification for the blackMarket class.
*******************************************************************************/
#include "Space.hpp"
#ifndef BLACKMARKET_HPP
#define BLACKMARKET_HPP

class blackMarket :
	public Space
{
protected:
	std::string police = "police.txt";
public:
	blackMarket();
	virtual ~blackMarket();
};

#endif 