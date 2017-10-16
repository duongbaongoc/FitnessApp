/*****************************************************************************************************************
* Programmer: Ngoc Bao Duong																					 *
* Class: CptS 122.01                                                                                             *
* Programming Assignment: Assignment 4																			 *
* Date: 07/06/2017												                         						 *
* Updated: 07/09/2017         																					 *
* Description: This file contains a class declaration of a node representing an exercise plan in a linked list.	 *																		 *
*****************************************************************************************************************/

#include <iostream>
#include <string>
#include "ExercisePlan.h"

using std::ostream;
using std::endl;
using std::string;

class ENode
{
public:

	/*****constructors*******/
	ENode(); //default
	ENode(const EPlan &plan); //parametrized
	ENode(const ENode &copyNode); //copy

								/*****getters*******/
	const EPlan &getPlan() const;
	ENode *getPNext() const;

	/*****setters*******/
	void setPlan(const EPlan &plan);
	void setPNext(ENode *pNext);

	/*****other functions*******/
	/*****destructors*******/
	~ENode();

private:
	EPlan mPlan;
	ENode *mPNext;
};

/******overloaded operator<<, insert content of a node to an outstream******/
ostream & operator<<(ostream &lhs, ENode *rhs);