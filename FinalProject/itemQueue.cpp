/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         11/15/2019
** Description:  This program contains the specification for the itemQueue class.
** It contains a pointer to the first QueueNode object as a member variable. It
** also contains five functions functions for queue operations - check to see if
** queue is empty, add value to back of queue, get value at front, remove the value
** at front, and print queue.
*******************************************************************************/
#include "itemQueue.hpp"



/*********************************************************************
*					itemQueue::itemQueue()
* This is the default constructor for the itemQueue. It initializes the value
* for the head to a nullptr.
*********************************************************************/
itemQueue::itemQueue()
{
	head = nullptr;
}

/*********************************************************************
*					itemQueue::~itemQueue()
* This is the default destructor for the itemQueue. It contains a garbage
* collector that deallocates all of the memory used by the list.
*********************************************************************/
itemQueue::~itemQueue()
{
	//Break the link at the back of list
	if (head != nullptr)
	{
		head->prev->next = nullptr;
	}
	//Start deallocating memory at the head of the list
	QueueNode* garbage = head;
	while (garbage != nullptr) 
	{
		head = head->next;
		garbage->next = nullptr;
		delete garbage;
		garbage = head;
	}
}

/*********************************************************************
*					itemQueue::getFront()
* This function prints the value at the head of the list.
*********************************************************************/
int itemQueue::getFront()
{
	if (head != nullptr)
	{
		return head->val;
	}
	else
	{
		//Return negative integer if itemQueue is empty
		return -1;
	}
}

/*********************************************************************
*					itemQueue::isEmpty()
* This function checks to see if the itemQueue is empty.
*********************************************************************/
bool itemQueue::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
*					itemQueue::addBack()
* This function adds a node at the back of the list. It takes in an
* integer from the user to be used as the value.
*********************************************************************/
void itemQueue::addBack(int usernumIn)
{
	QueueNode* nodePtr = head;
	if (isEmpty())
	{
		//If list is empty, allocate a new node to the head and 
		//have previous and next both point to head
		head = new QueueNode();
		head->val = usernumIn;
		head->prev = head;
		head->next = head;
	}
	else
	{
		if (head->next == head)
		{
			//This function adds a node when the only other node is the
			//head.
			nodePtr = new QueueNode();
			nodePtr->val = usernumIn;
			//Both the previous and next of new node point to head
			nodePtr->next = head;
			nodePtr->prev = head;
			//Change head pointers to make sure the link is circular
			head->prev = nodePtr;
			head->next = nodePtr;
		}
		else
		{
			nodePtr = new QueueNode();
			nodePtr->val = usernumIn;
			//Latest node to be added always has next point to head
			nodePtr->next = head;
			//Previous points to the current last node
			nodePtr->prev = head->prev;
			//Sets current last node to second from end
			head->prev->next = nodePtr;
			//Sets new node to last node
			head->prev = nodePtr;
		}
	}
}

/*********************************************************************
*					itemQueue::removeFront()
* This function deletes the first value in the list. It uses a node
* pointer to keep track of the head.
*********************************************************************/
void itemQueue::removeFront()
{
	//Hold location of head until operations are complete
	QueueNode* nodePtr = head;
	if (isEmpty())
	{
		std::cout << "Your itemQueue is empty." << std::endl;
	}
	else
	{
		if (head->next == head)
		{
			//If only one value in itemQueue, set head to null
			head = nullptr;
			delete nodePtr;
		}
		else
		{
			//Otherwise, change head pointers and delete
			//the current head
			head->prev->next = head->next;
			head->next->prev = head->prev;
			head = head->next;
			delete nodePtr;
		}
	}
}

/*********************************************************************
*					itemQueue::printQueue()
* This function traverses the list beginning with the first value. It
* first checks that the list is not empty.
*********************************************************************/
void itemQueue::printQueue()
{
	QueueNode* nodePtr = head;

	//If head is not null, print head value
	if (nodePtr != nullptr)
	{
		std::cout << " \n Your itemQueue is: " << std::endl;
		std::cout << nodePtr->val << "  ";

		//Loop if there is more than one value in the itemQueue
		while (nodePtr->next != head)
		{
			nodePtr = nodePtr->next;
			std::cout << nodePtr->val << "  ";
		}
	}
	else
	{
		std::cout << "Your itemQueue is empty." << std::endl;
	}
	std::cout << "\n" << std::endl;
}


