#include <iostream>
#include <string>
#include "Plan.h"

using std::ostream;
using std::endl;
using std::string;

class Node
{
public:

	/*****constructors*******/
	Node(); //default
	Node(const Plan &plan); //parametrized
	Node(const Node &copyNode); //copy

	/*****getters*******/
	const Plan &getPlan() const;
	Node *getPNext() const;

	/*****setters*******/
	void setPlan(const Plan &plan);
	void setPNext(Node *pNext);

	/*****other functions*******/
	/*****destructors*******/
	~Node();

private:
	Plan mPlan;
	Node *mPNext;
};

/******overloaded operator<<, insert content of a node to an outstream******/
ostream & operator<<(ostream &lhs, Node *rhs);