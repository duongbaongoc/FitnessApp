/*****************************************************************************************************************
* Programmer: Ngoc Bao Duong																					 *
* Class: CptS 122.01                                                                                             *
* Programming Assignment: Assignment 4																			 *
* Date: 07/06/2017												                         						 *
* Updated: 07/09/2017         																					 *
* Description: This file contains a class declaration of a node representing a diet plan in a linked list.		 *																		 *
*****************************************************************************************************************/

#include <iostream>
#include <string>
#include "DietPlan.h"

using std::ostream;
using std::endl;
using std::string;

class DietNode
{
public:

	/*****constructors*******/
	DietNode(); //default
	DietNode(const DietPlan &plan); //parametrized
	DietNode(const DietNode &copyNode); //copy

								/*****getters*******/
	const DietPlan &getPlan() const;
	DietNode *getPNext() const;

	/*****setters*******/
	void setPlan(const DietPlan &plan);
	void setPNext(DietNode *pNext);

	/*****other functions*******/
	/*****destructors*******/
	~DietNode();

private:
	DietPlan mPlan;
	DietNode *mPNext;
};

/******overloaded operator<<, insert content of a node to an outstream******/
ostream & operator<<(ostream &lhs, DietNode *rhs);