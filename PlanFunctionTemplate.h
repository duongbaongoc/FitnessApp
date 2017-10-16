#include "PlanClassTemplate.h"

/*********Constructor template**************************/
// default constructor
template <class T>
Plan<T>::Plan()
{
	m_goal = 0;
	m_plan_name = "";
	m_date = "";
}

// parametrized constructor
template <class T>
Plan::Plan(T goal, string name, string date)
{
	m_goal = goal;
	m_plan_name = name;
	m_date = date;
}

// copy constructor
template <class T>
Plan::Plan(const Plan &p1)
{
	m_goal = p1.get_goal();
	m_plan_name = p1.get_plan_name();
	m_date = p1.get_date();
}

/*******************GETTERS***********************************/
template <class T>
T Plan<T>::get_goal() const
{
	return m_goal;
}

template <class T>
const string &Plan<T>::get_plan_name() const
{
	return m_plan_name;
}

template <class T>
const string &Plan<T>::get_date() const
{
	return m_date;
}

/*******************SETTERS***********************************/
template <class T>
void Plan<T>::set_goal(T goal)
{
	m_goal = goal;
}

template <class T>
void Plan<T>::set_plan_name(const string &name)
{
	m_plan_name = name;
}

template <class T>
void Plan<T>::set_date(const string &date)
{
	m_date = date;
}

/*******************OTHER MEMBER FUNCTIONS***********************************/

//promt user for a goal, update the plan and display it
template <class T>
void Plan<T>::edit_goal()
{
	T goal = 0;
	cout << "New goal (i.e: 10213): ";
	cin >> goal;
	set_goal(goal); //update plan
	cout << *this; //display plan
}

//overloaded operator= : assign a plan to another plan
template <class T>
void Plan<T>::operator=(const Plan &rhs)
{
	set_date(rhs.get_date());
	set_goal(rhs.get_goal());
	set_plan_name(rhs.get_plan_name());
}

/*******************DESTRUCTORS***********************************/
template <class T>
void Plan<T>::~Plan()
{
	//nothing goes here
}

/****************NON MEMBER FUNCTIONS***********************/

//overloaded operator<< : insert a plan to an ostream
//to display a plan to screen
template <class T>
ostream & operator<<(ostream &lhs, const Plan<T> &rhs)
{
	lhs << rhs.get_plan_name() << endl;
	lhs << rhs.get_goal() << endl;
	lhs << rhs.get_date() << endl;
	return lhs;
}

//overloaded operator<< : insert a plan to an ofstream
//to write a plan to an output file
//postcondition: lhs (file) is open to write
template <class T>
ofstream & operator<<(ofstream &lhs, Plan<T> &rhs)
{
	lhs << "*******PLAN*******" << endl;
	lhs << "Plan name: " << rhs.get_plan_name() << endl;
	lhs << "Date: " << rhs.get_date() << endl;
	lhs << "Goal: " << rhs.get_goal() << endl;
	return lhs;
}

//overloaded operator>> : read a plan from a file
//postcondition: lhs (file) is open to read
template <class T>
ifstream & operator >> (ifstream &lhs, Plan<T> &rhs)
{
	T goal = 0;
	string name, date;

	lhs >> name >> goal >> date;

	rhs.set_plan_name(name);
	rhs.set_goal(goal);
	rhs.set_date(date);

	return lhs;
}