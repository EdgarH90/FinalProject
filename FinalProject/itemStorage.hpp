/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         12/1/2019
** Description:  This program contains the specification for the queue class.
** It contains a pointer to the first QueueNode object as a member variable. It
** also contains five functions functions for queue operations - check to see if 
** queue is empty, add value to back of queue, get value at front, remove the value 
** at front, and print queue.
*******************************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#ifndef ITEMQUEUE_HPP
#define ITEMQUEUE_HPP

//This struct represents each node
struct QueueNode
{
	int val = 0;
	QueueNode* next;
	QueueNode* prev;
};

class itemStorage
{
private: 
	QueueNode* head;
public:
	itemStorage();
	~itemStorage();
	bool isEmpty();
	void addBack(int val);
	int getFront();
	void removeFront();
	void printQueue();
};

#endif