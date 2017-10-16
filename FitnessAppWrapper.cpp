/*****************************************************************************************************************
* Programmer: Ngoc Bao Duong																					 *
* Class: CptS 122.01                                                                                             *
* Programming Assignment: Assignment 4																			 *
* Date: 07/06/2017												                         						 *
* Updated: 07/09/2017         																					 *
* Description: This file contains functions' declaration simulating a fitness application.						 *
*****************************************************************************************************************/

#include "FitnessAppWrapper.h"

/******************************************************************/
/********Member functions, constructors, destructor****************/
/******************************************************************/

/*****default constructor*******/
FitnessAppWrapper::FitnessAppWrapper()
{
	m_diet_plan.setpHead(nullptr);
	m_exercise_plan.setpHead(nullptr);
	m_diet_file.open("dietPlans.txt");
	m_exercise_file.open("exercisePlans.txt");
}

/*****parametrized constructor*******/
FitnessAppWrapper::FitnessAppWrapper(string diet_file_name,
	string exercise_file_name)
{
	m_diet_plan.setpHead(nullptr);
	m_exercise_plan.setpHead(nullptr);
	m_diet_file.open(diet_file_name);
	m_exercise_file.open(exercise_file_name);
}

/*****getters*******/
const DietList &FitnessAppWrapper::get_diet_plan() const
{
	return m_diet_plan;
}

const EList &FitnessAppWrapper::get_exercise_plan() const
{
	return m_exercise_plan;
}
 
const fstream &FitnessAppWrapper::get_diet_file() const
{
	return m_diet_file;
}

const fstream &FitnessAppWrapper::get_exercise_file() const
 {
	 return m_exercise_file;
 }

/*****setters*******/
void FitnessAppWrapper::set_diet_plan(const DietList &diet_plan)
{
	m_diet_plan = diet_plan;
}

void FitnessAppWrapper::set_exercise_plan(const EList &exercise_plan)
{
	m_exercise_plan = exercise_plan;
}

void FitnessAppWrapper::set_diet_file(const string &diet_file_name)
{
	if (m_diet_file)
		m_diet_file.close();
	m_diet_file.open(diet_file_name);
}

void FitnessAppWrapper::set_exercise_file(const string &exercise_file_name)
{
	if (m_exercise_file)
		m_exercise_file.close();
	m_exercise_file.open(exercise_file_name);
}

/*****destructors*******/
FitnessAppWrapper::~FitnessAppWrapper()
{
	if(m_diet_file)
		m_diet_file.close();
	if (m_exercise_file)
		m_exercise_file.close();
}


/******************************************************************/
/***************Other member functions*****************************/
/******************************************************************/

//display 9 options to screen
void FitnessAppWrapper::displayMenu() const
{
	cout << "Option menu: " << endl;
	cout << "\t\t1.    Load weekly diet plan from file." << endl;
	cout << "\t\t2.    Load weekly exercise plan from file." << endl;
	cout << "\t\t3.    Store weekly diet plan to file." << endl;
	cout << "\t\t4.    Store weekly exercise plan to file." << endl;
	cout << "\t\t5.    Display weekly diet plan to screen." << endl;
	cout << "\t\t6.    Display weekly exercise plan to screen." << endl;
	cout << "\t\t7.    Edit daily diet plan." << endl;
	cout << "\t\t8.    Edit daily exercise plan." << endl;
	cout << "\t\t9.    Exit." << endl << endl;
}

//read one record from the given stream
//Precondition: file is already open!
void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, DietPlan &plan)
{
	string name, date, discard;
	int goal = 0;
	getline(fileStream, name); //get name plan
	fileStream >> goal; //get goal
	getline(fileStream, discard); //discard the '\n' after goal
	getline(fileStream, date); //get date
	getline(fileStream, discard); //discard the empty line
	plan.set_plan_name(name);
	plan.set_goal(goal);
	plan.set_date(date);
}
void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, EPlan &plan)
{
	string name, date, discard;
	int goal = 0;
	getline(fileStream, name); //get name plan
	fileStream >> goal; //get goal
	getline(fileStream, discard); //discard the '\n' after goal
	getline(fileStream, date); //get date
	getline(fileStream, discard); //discard the empty line
	plan.set_plan_name(name);
	plan.set_goal(goal);
	plan.set_date(date);
}

//read one record from the given stream
//Precondition: FitnessAppWrapper::loadDailyPlan() is defined
//file is opened
void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, DietList &plan_list)
{
	DietPlan current_plan;
	clearList(plan_list); //clear out the list - delete all nodes
	while (!fileStream.eof())
	{
		loadDailyPlan(fileStream, current_plan); //read in one plan from file
		plan_list.insert_at_end(*(new DietNode(current_plan))); //add that plan to the linked list
	}
	cout << "Done loading weekly plan from the file." << endl;
}
void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, EList &plan_list)
{
	EPlan current_plan;
	clearList(plan_list); //clear out the list - delete all nodes
	while (!fileStream.eof())
	{
		loadDailyPlan(fileStream, current_plan); //read in one plan from file
		plan_list.insert_at_end(*(new ENode(current_plan))); //add that plan to the linked list
	}
	cout << "Done loading weekly plan from the file." << endl;
}


//write a daily plan to the screen
void FitnessAppWrapper::displayDailyPlan(const DietPlan &plan)
{
	cout << plan << endl;
}
void FitnessAppWrapper::displayDailyPlan(const EPlan &plan)
{
	cout << plan << endl;
}

//write a daily plan to the screen
//FitnessAppWrapper::displayDailyPlan() is defined
void FitnessAppWrapper::displayWeeklyPlan(const DietList &list)
{
	DietNode *pCur = list.getPHead();
	if (pCur == nullptr)
		cout << "No plan found to display." << endl;
	while (pCur)
	{
		displayDailyPlan(pCur->getPlan());
		pCur = pCur->getPNext();
	}
}
void FitnessAppWrapper::displayWeeklyPlan(const EList &list)
{
	ENode *pCur = list.getPHead();
	if (pCur == nullptr)
		cout << "No plan found to display." << endl;
	while (pCur)
	{
		displayDailyPlan(pCur->getPlan());
		pCur = pCur->getPNext();
	}
}

//write a daily plan to a file
void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, const DietPlan &plan)
{
	fileStream << plan;
}
void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, const EPlan &plan)
{
	fileStream << plan;
}

//write a weekly plan to a file
//FitnessAppWrapper::storeDailyPlan() is defined
void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, const DietList &list)
{
	DietNode *pCur = list.getPHead();
	int count = 0;
	while (pCur && count <6)
	{
		storeDailyPlan(fileStream, pCur->getPlan());
		fileStream << endl;
		pCur = pCur->getPNext();
		count++;
	}
	storeDailyPlan(fileStream, pCur->getPlan());
	cout << "Stored all plans from the list to the file successully." << endl;
}
void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, const EList &list)
{
	ENode *pCur = list.getPHead();
	int count = 0;
	while (pCur && count <6)
	{
		storeDailyPlan(fileStream, pCur->getPlan());
		fileStream << endl;
		pCur = pCur->getPNext();
		count++;
	}
	storeDailyPlan(fileStream, pCur->getPlan());
	cout << "Stored all plans from the list to the file successully." << endl;
}

//promt for info then update the plan (list)
//Plan::edit_goal() is defined
void FitnessAppWrapper::editPlan(DietList &plan)
{
	string name;
	string new_name, new_date;
	int new_goal = 0;
	DietNode *pCur = plan.getPHead();

	cout << "Please provide name of the plan you want to edit (i.e: Diet 1/Exercise 6): ";
	std::getline(cin, name); //prompt user for a plan name
	std::getline(cin, name); //prompt user for a plan name

	while ( pCur != nullptr &&
		(pCur->getPlan().get_plan_name()).compare(name) != 0) //search for the plan in the list
	{
		pCur = pCur->getPNext();
	}

	if (pCur == nullptr)
		cout << "No such plan found." << endl;
	else //found the plan => edit
	{
		displayDailyPlan(pCur->getPlan());//show the plan
		//promt use for new info
		cout << endl << "Please provide new info to update the plan: " << endl;
		cout << "New plan name (i.e: <any string>): ";
		std::getline(cin,new_name);
		cout << "New date (i.e: 01/28/2017): ";
		std::getline(cin, new_date);
		cout << "New goal (i.e: 10213): ";
		cin >> new_goal;
		//update the plan accordingly
		pCur->setPlan(*(new DietPlan(new_goal, new_name, new_date)));
		cout << "Done updating the plan." << endl;
	}
}
void FitnessAppWrapper::editPlan(EList &plan)
{
	string name;
	string new_name, new_date;
	int new_goal = 0;
	ENode *pCur = plan.getPHead();

	cout << "Please provide name of the plan you want to edit (i.e: Diet 1/Exercise 6): ";
	std::getline(cin, name); //prompt user for a plan name
	std::getline(cin, name); //prompt user for a plan name

	while (pCur != nullptr &&
		(pCur->getPlan().get_plan_name()).compare(name) != 0) //search for the plan in the list
	{
		pCur = pCur->getPNext();
	}

	if (pCur == nullptr)
		cout << "No such plan found." << endl;
	else //found the plan => edit
	{
		displayDailyPlan(pCur->getPlan());//show the plan
										  //promt use for new info
		cout << endl << "Please provide new info to update the plan: " << endl;
		cout << "New plan name (i.e: <any string>): ";
		std::getline(cin, new_name);
		cout << "New date (i.e: 01/28/2017): ";
		std::getline(cin, new_date);
		cout << "New goal (i.e: 10213): ";
		cin >> new_goal;
		//update the plan accordingly
		pCur->setPlan(*(new EPlan(new_goal, new_name, new_date)));
		cout << "Done updating the plan." << endl;
	}
}

//write the most recent weekly plans to the corresponding files
//FitnessAppWrapper::storeWeeklyPlan() is defined
void FitnessAppWrapper::exit()
{
	if (m_diet_plan.getPHead() != nullptr)
		storeWeeklyPlan(m_diet_file, m_diet_plan);
	if (m_exercise_plan.getPHead() != nullptr)
		storeWeeklyPlan(m_exercise_file, m_exercise_plan);
}

//run the main application
void FitnessAppWrapper::runApp()
{
	int option = 0;

	//promt a valid option then execute the option
	do
	{
		get_option(*this, option);
		switch (option)
		{
		case 1: //Load weekly diet plan from file.
			if (m_diet_file.is_open())
				m_diet_file.close();
			m_diet_file.open("dietPlans.txt");
			loadWeeklyPlan(m_diet_file, m_diet_plan);
			break;
		case 2: //Load weekly exercise plan from file.
			if (m_exercise_file.is_open())
				m_exercise_file.close();
			m_exercise_file.open("exercisePlans.txt");
			loadWeeklyPlan(m_exercise_file, m_exercise_plan);
			break;
		case 3: //Store weekly diet plan to file.
			if (m_diet_file.is_open())
				m_diet_file.close();
			m_diet_file.open("dietPlans.txt", 'w');
			storeWeeklyPlan(m_diet_file, m_diet_plan);
			break;
		case 4: //Store weekly exercise plan to file.
			if (m_exercise_file.is_open())
				m_exercise_file.close();
			m_exercise_file.open("exercisePlans.txt", 'w');
			storeWeeklyPlan(m_exercise_file, m_exercise_plan);
			break;
		case 5: //Display weekly diet plan to screen.
			displayWeeklyPlan(m_diet_plan);
			break;
		case 6: //Display weekly exercise plan to screen.
			displayWeeklyPlan(m_exercise_plan);
			break;
		case 7: //Edit daily diet plan.
			editPlan(m_diet_plan);
			break;
		case 8: //Edit daily exercise plan.
			editPlan(m_exercise_plan);
			break;
		case 9: //Exit.
			if (m_diet_file.is_open())
				m_diet_file.close();
			m_diet_file.open("dietPlans.txt", 'w');
			if (m_exercise_file.is_open())
				m_exercise_file.close();
			m_exercise_file.open("exercisePlans.txt", 'w');
			exit();
			break;
		}
		system("pause");
		system("cls");
	} while (option != 9);
}

/******************************************************************/
/*****************Non member functions*****************************/
/******************************************************************/

//get an option (1-9) from the option menu
void get_option(const FitnessAppWrapper &obj, int &option)
{
	option = 0; //reset option
	int count = 0;
	obj.displayMenu(); //display option menu
	do
	{
		if (count == 0) //promt for the first time
			cout << "Please provide an option 1-9(i.e: 4): ";
		else
			cout << "Your input is invalid. Please provide an option 1-9(i.e: 4): ";
		cin >> option;
		count++;
	} while (option < 1 || option > 9);
}