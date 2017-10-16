/*****************************************************************************************************************
* Programmer: Ngoc Bao Duong																					 *
* Class: CptS 122.01                                                                                             *
* Programming Assignment: Assignment 4																			 *
* Date: 07/06/2017												                         						 *
* Updated: 07/09/2017         																					 *
* Description: This file contains functions' declaration relating to an exercise plan list.						 *
*****************************************************************************************************************/

#include "EList.h"

/******************************************************************/
/********Member functions, constructors, destructor****************/
/******************************************************************/

/*****default constructor*******/
EList::EList()
{
	mPHead = nullptr;
}

/*****deep copy constructor*******/
/*Copy content of all nodes of the copy-list to the refered list*/
EList::EList(const EList &copyList)
{
	*this = copyList;
}

/*****getter*******/
ENode * EList::getPHead() const
{
	return mPHead;
}

/*****setter*******/
void EList::setpHead(ENode * const node)
{
	mPHead = node;
}

/*****other memfunctions*******/

//insert a plan (node) at end of the list
void EList::insert_at_end(ENode &node)
{
	insert_at_end(mPHead, node);
}

//helper function - insert a plan (node) at end of the list
void EList::insert_at_end(ENode *&pHead, ENode &node)
{
	ENode *pLast = pHead;
	//find the last node
	if (pLast != nullptr) //not empty list
		while (pLast->getPNext() != nullptr)
		{
			pLast = pLast->getPNext();
		}
	//last node found -> insert the new node
	if (pLast == nullptr) //insert to empty list
		pHead = &node;
	else
		pLast->setPNext(&node);
}

//overloaded operator=, assign a list to another list, deep copy
void EList::operator=(const EList &rhs)
{
	ENode *pCur = rhs.getPHead(); //each node in the rhs list
	ENode *pLast = nullptr;
	while (pCur != nullptr)
	{
		ENode *pMem = new ENode(); //new node to insert to the refered list
								 //copy all content from the current node to new node
		pMem->setPlan(pCur->getPlan());
		//connect the last node of the refered list to the new node
		if (pLast == nullptr) //pMem is the first to add in
		{
			setpHead(pMem);
		}
		else
			pLast->setPNext(pMem);
		//update statements
		pCur = pCur->getPNext();
		pLast = pMem;
	}
}

/*****destructors*******/
//delete all nodes of the list
EList::~EList()
{
	ENode *pCur = mPHead, *pPrev = nullptr;
	while (pCur != nullptr)
	{
		pPrev = pCur;
		pCur = pCur->getPNext();
		delete pPrev;
		pPrev = nullptr;
	}
	if (pPrev)
		delete pPrev;
	setpHead(nullptr);
}

/******************************************************************/
/***************Non member functions*******************************/
/******************************************************************/

/******overloaded operator<<, insert content of a list to an outstream******/
ostream & operator<<(ostream & lhs, const EList &l)
{
	ENode *pCur = l.getPHead();
	lhs << "The list:" << endl;
	while (pCur != nullptr)
	{
		lhs << pCur;
		pCur = pCur->getPNext();
	}
	lhs << "List ends." << endl;
	return lhs;
}

/******Delete all nodes of a list**********/
void clearList(EList &l)
{
	ENode *pCur = l.getPHead(), *pPrev = nullptr;
	while (pCur != nullptr)
	{
		pPrev = pCur;
		pCur = pCur->getPNext();
		delete pPrev;
		pPrev = nullptr;
	}
	if (pPrev)
		delete pPrev;
	l.setpHead(nullptr);
}