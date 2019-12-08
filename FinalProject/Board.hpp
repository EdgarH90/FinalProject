/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/7/2019
** Description:  This program contains the specification for the readMatrix function.
** The function takes in a matrix in the form of a pointer to a 2D array, and its size
** as parameters. It then prompts the user for all numbers within the matrix.
** (Modified from project 1)
*******************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

//Board class declaration
class Board
{
private:
	int userRow = 0;
	int userCol = 0;
	char **userBoard; // Point to array

public:
	Board(int row, int col); // Constructor that initializes empty array
	~Board(); //Destructor deletes allocated memory
	void showBoard(int xPos, int yPos); //Displays the board state
	char getboardCoord(int X, int Y); //Gets current board coordinates
	void changeColor(int X, int Y); //Changes tile colors
	void resetTile(int xPos, int yPos); //Resets tile if item is collected
};
#endif
