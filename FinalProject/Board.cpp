/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/7/2019
** Description:  This program contains the implementation for the Board class.
** It contains several functions for creating and updating the game map.
** (Modified from project 1)
*******************************************************************************/
#include <string>
#include<iostream>
#include <iomanip>
#include "Board.hpp"
#include "inputValidation.hpp"

/*********************************************************************
*					Board::Board(int, int)
* This is the default constructor that takes in two ints as parameters
* and uses them to dynamically allocate a 2D array for the board.
*********************************************************************/

Board::Board(int rowNum, int colNum)
{
	userRow = rowNum;
	userCol = colNum;
	userBoard = new char*[rowNum];
	for (int i = 0; i < rowNum; i++)
		userBoard[i] = new char[colNum];

	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			userBoard[i][j] = ' ';
		}
	}

}

/*********************************************************************
*					Board::Board()
* This is the default destructor that deletes the allocated memory by
* looping through the 2D Array rows.
*********************************************************************/

Board::~Board()
{
	//Deleting memory from heap to prevent leaks
	for (int i = 0; i < userRow; ++i)
	{
		delete[] userBoard[i];
	}
	delete[]userBoard;
}

/*********************************************************************
*					Board::showBoard(int, int)
* This function takes in two ints for the x and y position as parameters.
* It prints out the current state of the game board by displaying the
* values in the  array. If the user is in the current position,
* it will print the user.
*********************************************************************/

void Board::showBoard(int xPos, int yPos)
{
	std::cout << " " << std::endl;

	for (int col = 0; col < (userCol+1); col++)
		std::cout << std::left<< std::setw(3) << "_";

	std::cout << std::endl;

	for (int row = 0; row < userRow; row++)
	{
		std::cout << "|";
		for (int col = 0; col < userCol; col++)
		{
			if ((row == xPos) && (col == yPos)) //Print the user if it is in the current position
			{
				std::cout << "*" << " " << std::setw(2);
			}
			else
				std::cout << userBoard[row][col] << " " << std::setw(2); //Displays board values in grid format
		}
		std::cout << std::setw(2) << "|" << std::endl;
	}

	for (int col = 0; col < (userCol + 1); col++)
		std::cout << std::setw(3) << "-";

	std::cout << std::endl;
}

/*********************************************************************
*					Board::getBoardCoord(int, int)
* This function returns the value of the board where the current user position is.
*********************************************************************/

char Board::getboardCoord(int xPos, int yPos)
{
	return userBoard[xPos][yPos];
}

/*********************************************************************
*					Board::resetTile(int, int)
* This function resets the value of the board where the current user position is.
*********************************************************************/

void Board::resetTile(int xPos, int yPos)
{
	userBoard[xPos][yPos] = ' ';
}


/*********************************************************************
*					Board::changeColor(char board[])
* This function changes the "color" of the current board coordinate based
* on the existing color. The function also randomly generates items 
* and danger zones for the different maps by taking in an int for the
* space type as a parameter.
*********************************************************************/

void Board::changeColor(int userX, int userY, int spaceType)
{
	//Random number between 0 and 1.00
	double randNum = ((double)rand() / (double)RAND_MAX);
	int randX = rand() % 3 +1;
	int randY = rand() % 3 + 1;

	//The spaceType denotes the object calling the function
	if (spaceType == 1)
	{
		if (randNum < .5)
		{
			userBoard[randX][randY] = 'D';
		}
		else if (randNum > .55 && randX != userX && randY != userY)
		{
			userBoard[randX][randY] = '#';
		}
		else
		{
			userBoard[randX][randY] = ' ';
		}
	}
	else if (spaceType == 2)
	{
		if (randNum < .5)
		{
			userBoard[randX][randY] = '?';
		}
		else if (randNum > .5 && randX != userX && randY != userY)
		{
			userBoard[randX][randY] = 'O';
		}
		else
		{
			userBoard[randX][randY] = ' ';
		}
	}
	else if (spaceType == 3)
	{
		if (randNum < .45)
		{
			userBoard[randX][randY] = 'S';
		}
		else if (randNum > .5 && randX != userX && randY != userY)
		{
			userBoard[randX][randY] = 'O';
		}
		else
		{
			userBoard[randX][randY] = ' ';
		}
	}
	else if (spaceType == 4)
	{
		if (randNum < .45)
		{
			userBoard[randX][randY] = '~';
		}
		else if (randNum > .5 && randX != userX && randY != userY)
		{
			userBoard[randX][randY] = '0';
		}
		else
		{
			userBoard[randX][randY] = ' ';
		}
	}
	else
	{
		randNum = ((double)rand() / (double)RAND_MAX);
		randX = rand() % 5 + 1;
		randY = rand() % 5 + 1;

		if (randNum < .5)
		{
			userBoard[randX][randY] = '1';
		}
		else if (randNum > .55 && randX != userX && randY != userY)
		{
			userBoard[randX][randY] = '?';
		}
		else
		{
			userBoard[randX][randY] = ' ';
		}
	}
}
