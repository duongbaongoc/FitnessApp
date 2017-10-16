/*****************************************************************************************************************
* Programmer: Ngoc Bao Duong																					 *
* Class: CptS 122.01                                                                                             *
* Programming Assignment: Assignment 4																			 *
* Date: 07/06/2017												                         						 *
* Updated: 07/09/2017         																					 *
* Description: This file contains a class declaration of a diet linked list.									 *
*****************************************************************************************************************/

#include <iostream>
#include "DietListNode.h"

class DietList
{
public:

	/*****constructors*******/
	DietList(); //default
	DietList(const DietList &copyList); //deep copy

								/*****getter*******/
	DietNode * getPHead() const;

	/*****setter*******/
	void setpHead(DietNode * const node);

	/*****other functions*******/
	void insert_at_end(DietNode &node); //insert a plan at end of the list
	void operator=(const DietList &l); //overloaded operator=, assign a list to another list, deep copy

								   /*****destructors*******/
	~DietList();

private:
	DietNode *mPHead;
	void insert_at_end(DietNode *&pHead, DietNode &node); //helper function - insert a plan at end of the list
};

/******overloaded operator<<, insert content of a list to an outstream******/
ostream & operator<<(ostream & lhs, const DietList &l);

/******Delete all nodes of a list**********/
void clearList(DietList &l);