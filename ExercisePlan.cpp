/*****************************************************************************************************************
* Programmer: Ngoc Bao Duong																					 *
* Class: CptS 122.01                                                                                             *
* Programming Assignment: Assignment 4																			 *
* Date: 07/06/2017												                         						 *
* Updated: 07/09/2017         																					 *
* Description: This file contains functions' declaration relating to an exercise plan.							 *
*****************************************************************************************************************/

#include "ExercisePlan.h"

/*********Constructor template**************************/
// default constructor
EPlan::EPlan()
{
	m_goal = 0;
	m_plan_name = "";
	m_date = "";
}

// parametrized constructor
EPlan::EPlan(int goal, string name, string date)
{
	m_goal = goal;
	m_plan_name = name;
	m_date = date;
}

// copy constructor
EPlan::EPlan(const EPlan &p1)
{
	m_goal = p1.get_goal();
	m_plan_name = p1.get_plan_name();
	m_date = p1.get_date();
}

/*******************GETTERS***********************************/
int EPlan::get_goal() const
{
	return m_goal;
}

const string &EPlan::get_plan_name() const
{
	return m_plan_name;
}

const string &EPlan::get_date() const
{
	return m_date;
}

/*******************SETTERS***********************************/
void EPlan::set_goal(int goal)
{
	m_goal = goal;
}

void EPlan::set_plan_name(const string &name)
{
	m_plan_name = name;
}

void EPlan::set_date(const string &date)
{
	m_date = date;
}

/*******************OTHER MEMBER FUNCTIONS***********************************/

//promt user for a goal, update the plan and display it
void EPlan::edit_goal()
{
	int goal = 0;
	cout << "New goal (i.e: 10213): ";
	cin >> goal;
	set_goal(goal); //update plan
	cout << *this; //display plan
}

//overloaded operator= : assign a plan to another plan
void EPlan::operator=(const EPlan &rhs)
{
	set_date(rhs.get_date());
	set_goal(rhs.get_goal());
	set_plan_name(rhs.get_plan_name());
}

/*******************DESTRUCTORS***********************************/
EPlan::~EPlan()
{
	//nothing goes here
}

/****************NON MEMBER FUNCTIONS***********************/

//overloaded operator<< : insert a plan to an ostream
//to display a plan to screen
ostream & operator<<(ostream &lhs, const EPlan &rhs)
{
	lhs << rhs.get_plan_name() << endl;
	lhs << rhs.get_goal() << endl;
	lhs << rhs.get_date() << endl;
	return lhs;
}

//overloaded operator<< : insert a plan to an ofstream
//to write a plan to an output file
//postcondition: lhs (file) is open to write
ofstream & operator<<(ofstream &lhs, EPlan &rhs)
{
	lhs << "*******PLAN*******" << endl;
	lhs << "Plan name: " << rhs.get_plan_name() << endl;
	lhs << "Date: " << rhs.get_date() << endl;
	lhs << "Goal: " << rhs.get_goal() << endl;
	return lhs;
}

//overloaded operator>> : read a plan from a file
//postcondition: lhs (file) is open to read
ifstream & operator >> (ifstream &lhs, EPlan &rhs)
{
	int goal = 0;
	string name, date;

	lhs >> name >> goal >> date;

	rhs.set_plan_name(name);
	rhs.set_goal(goal);
	rhs.set_date(date);

	return lhs;
}