/*****************************************************************************************************************
* Programmer: Ngoc Bao Duong																					 *
* Class: CptS 122.01                                                                                             *
* Programming Assignment: Assignment 4																			 *
* Date: 07/06/2017												                         						 *
* Updated: 07/09/2017         																					 *
* Description: This file contains a class declaration representing an execies plan.								 *																		 *
*****************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using std::ostream;
using std::istream;
using std::endl;
using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::string;

class EPlan
{
public:
	//constructors
	EPlan(); // default
	EPlan(int goal, string name, string date); //parametrized
	EPlan(const EPlan &p1); // copy

						  //getters
	int get_goal() const;
	const string &get_plan_name() const;
	const string &get_date() const;

	//setters
	void set_goal(int calo);
	void set_plan_name(const string &name);
	void set_date(const string &date);

	//other member functions
	void edit_goal(); //promt for a goal, update the plan and display it
	void operator= (const EPlan &rhs); //overloaded operator= : assign a plan to another plan
									  //destructor
	~EPlan();

private:
	int m_goal;
	string m_plan_name;
	string m_date;
};


//overloaded operator<< : insert a plan to an ostream
//to display a plan to screen
ostream & operator<<(ostream &lhs, const EPlan &rhs);

//overloaded operator<< : insert a plan to an ofstream
//to write a plan to an output file
//postcondition: lhs (file) is open to write
ofstream & operator<<(ofstream &lhs, EPlan &rhs);

//overloaded operator>> : read a plan from a file
//postcondition: lhs (file) is open to read
ifstream & operator >> (ifstream &lhs, EPlan &rhs);