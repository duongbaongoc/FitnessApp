/*****************************************************************************************************************
* Programmer: Ngoc Bao Duong																					 *
* Class: CptS 122.01                                                                                             *
* Programming Assignment: Assignment 4																			 *
* Date: 07/06/2017												                         						 *
* Updated: 07/09/2017         																					 *
* Description: This file contains a function declaration of a node (class) representing an exercise plan		 *
*					in a linked list.																			 *
*****************************************************************************************************************/

#include "EListNode.h"

/******************************************************************/
/********Member functions, constructors, destructor****************/
/******************************************************************/

/*****default constructor*******/
ENode::ENode()
{
	mPlan = *(new EPlan(0, "", ""));
	mPNext = nullptr;
}

/*****parametrized constructor*******/
ENode::ENode(const EPlan &plan)
{
	mPlan = plan;
	mPNext = nullptr;
}

/*****copy constructor*******/
ENode::ENode(const ENode &copyNode)
{
	mPlan = copyNode.getPlan();
	mPNext = copyNode.getPNext();
}

/*****getters*******/
const EPlan & ENode::getPlan() const
{
	return mPlan;
}

ENode *ENode::getPNext() const
{
	return mPNext;
}

/*****setters*******/
void ENode::setPlan(const EPlan &plan)
{
	mPlan = plan;
}

void ENode::setPNext(ENode *pNext)
{
	mPNext = pNext;
}

/*****other functions*******/
/*****destructors*******/
ENode::~ENode()
{
	setPNext(nullptr);
	//mPlan and its node is created in the same scope
	//when the node leaves the scope, mPlan will acticate its destructor 
}


/******************************************************************/
/***************Non member functions*******************************/
/******************************************************************/

/******overloaded operator<<, insert content of a node to an outstream******/
ostream & operator<<(ostream &lhs, ENode *rhs)
{
	lhs << rhs->getPlan();
	return lhs;
}