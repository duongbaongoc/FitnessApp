/*****************************************************************************************************************
* Programmer: Ngoc Bao Duong																					 *
* Class: CptS 122.01                                                                                             *
* Programming Assignment: Assignment 4																			 *
* Date: 07/06/2017												                         						 *
* Updated: 07/09/2017         																					 *
* Description: This file contains a class declaration of an exercise linked list.								 *
*****************************************************************************************************************/

#include <iostream>
#include "EListNode.h"

class EList
{
public:

	/*****constructors*******/
	EList(); //default
	EList(const EList &copyList); //deep copy

								/*****getter*******/
	ENode * getPHead() const;

	/*****setter*******/
	void setpHead(ENode * const node);

	/*****other functions*******/
	void insert_at_end(ENode &node); //insert a plan at end of the list
	void operator=(const EList &l); //overloaded operator=, assign a list to another list, deep copy

								   /*****destructors*******/
	~EList();

private:
	ENode *mPHead;
	void insert_at_end(ENode *&pHead, ENode &node); //helper function - insert a plan at end of the list
};

/******overloaded operator<<, insert content of a list to an outstream******/
ostream & operator<<(ostream & lhs, const EList &l);

/******Delete all nodes of a list**********/
void clearList(EList &l);