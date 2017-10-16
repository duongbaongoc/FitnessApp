/*****************************************************************************************************************
* Programmer: Ngoc Bao Duong																					 *
* Class: CptS 122.01                                                                                             *
* Programming Assignment: Assignment 4																			 *
* Date: 07/06/2017												                         						 *
* Updated: 07/09/2017         																					 *
* Description: This file contains a function declaration of a node (class) representing a diet plan				 *
*					in a linked list.																			 *
*****************************************************************************************************************/

#include "DietListNode.h"

/******************************************************************/
/********Member functions, constructors, destructor****************/
/******************************************************************/

/*****default constructor*******/
DietNode::DietNode()
{
	mPlan = *(new DietPlan(0, "", ""));
	mPNext = nullptr;
}

/*****parametrized constructor*******/
DietNode::DietNode(const DietPlan &plan)
{
	mPlan = plan;
	mPNext = nullptr;
}

/*****copy constructor*******/
DietNode::DietNode(const DietNode &copyNode)
{
	mPlan = copyNode.getPlan();
	mPNext = copyNode.getPNext();
}

/*****getters*******/
const DietPlan & DietNode::getPlan() const
{
	return mPlan;
}

DietNode *DietNode::getPNext() const
{
	return mPNext;
}

/*****setters*******/
void DietNode::setPlan(const DietPlan &plan)
{
	mPlan = plan;
}

void DietNode::setPNext(DietNode *pNext)
{
	mPNext = pNext;
}

/*****other functions*******/
/*****destructors*******/
DietNode::~DietNode()
{
	setPNext(nullptr);
	//mPlan and its node is created in the same scope
	//when the node leaves the scope, mPlan will acticate its destructor 
}


/******************************************************************/
/***************Non member functions*******************************/
/******************************************************************/

/******overloaded operator<<, insert content of a node to an outstream******/
ostream & operator<<(ostream &lhs, DietNode *rhs)
{
	lhs << rhs->getPlan();
	return lhs;
}