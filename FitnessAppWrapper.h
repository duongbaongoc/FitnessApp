/*****************************************************************************************************************
* Programmer: Ngoc Bao Duong																					 *
* Class: CptS 122.01                                                                                             *
* Programming Assignment: Assignment 4																			 *
* Date: 07/06/2017												                         						 *
* Updated: 07/09/2017         																					 *
* Description: This file contains functions' declaration simulating a fitness application.						 *
*****************************************************************************************************************/

#include "DietList.h"
#include "EList.h"

using std::fstream;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

/****represent the whole application*****/
class FitnessAppWrapper
{
	public:
		//constructors
		FitnessAppWrapper(); // default
		FitnessAppWrapper(string diet_file_name, 
			string exercise_file_name); // parametrized

		//getters
		const DietList &get_diet_plan() const;
		const EList &get_exercise_plan() const;
		const fstream &get_diet_file() const;
		const fstream &get_exercise_file() const;

		//setters
		void set_diet_plan(const DietList &diet_plan);
		void set_exercise_plan(const EList &exercise_plan);
		void set_diet_file(const string &file_file_name);
		void set_exercise_file(const string &exercise_file_name);

		//other member functions
		void runApp(void); // start the main application, execute the option
		void loadDailyPlan(fstream &fileStream, DietPlan &plan);
		void loadDailyPlan(fstream &fileStream, EPlan &plan);
		//must define two of these functions; one for a DietPlan and one for an ExercisePlan.
		//This function reads one record from the given stream.These will be considered overloaded functions!
			//Precondition: file is already open!
		void loadWeeklyPlan(fstream &fileStream, DietList &plan_list);
		void loadWeeklyPlan(fstream &fileStream, EList &plan_list);
		//must define two of these functions; one for a DietPlan and one for an ExercisePlan.
		//This function must read in all seven daily plans from the given stream.
		void displayDailyPlan(const DietPlan &plan);
		void displayDailyPlan(const EPlan &plan);
		//writes a daily plan to the screen.
		//You must apply the overloaded stream insertion operator here!
	//Note : you must determine the appropriate parameters and return type.Once again you must define two of these!
		void displayWeeklyPlan(const DietList &list);
		void displayWeeklyPlan(const EList &list);
		//writes a weekly plan to the screen.This function must call displayDailyPlan().
	//Note : you must determine the appropriate parameters and return type.Once again you must define two of these!
		void storeDailyPlan(fstream &fileStream, const DietPlan &plan);
		void storeDailyPlan(fstream &fileStream, const EPlan &plan);
		//writes a daily plan to a file.You must apply the overloaded stream insertion operator here!
	//Note : you must determine the appropriate parameters and return type.Once again you must define two of these!
		void storeWeeklyPlan(fstream &fileStream, const DietList &list);
		void storeWeeklyPlan(fstream &fileStream, const EList &list);
		//writes a weekly plan to a file.This function must call storeDailyPlan().
		//You must apply the overloaded stream insertion operator here!
	//Note : you must determine the appropriate parameters and return type.Once again you must define two of these!
		void displayMenu() const; // displays nine menu options
		void editPlan(DietList &plan); //promt for info then update the plan (list)
		void editPlan(EList &plan);
		void exit(); //write the most recent weekly plans to the corresponding file
		//destructor
		~FitnessAppWrapper();
	private:
		DietList m_diet_plan;
		EList m_exercise_plan;
		fstream m_diet_file;
		fstream m_exercise_file;
};

//get an option (1-9) from the option menu
void get_option(const FitnessAppWrapper &obj, int &option);

