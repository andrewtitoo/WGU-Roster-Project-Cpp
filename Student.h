#pragma once
#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
	//declare strings
	const static int courseArraySize = 3;
private:
	string studentID;
	string firstname;
	string lastname;
	string emailaddress;
	int age;
	double courses[courseArraySize];
	DegreeType degreeType;

public:
	Student();
	//full constructor
	Student(string studentID, string firstname, string lastname, string emailaddress, int age, double courses[], DegreeType degreeType);
	//destructor
	~Student();

	//getters
	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	double* getCourses();
	DegreeType getDegreeType() const;

	//setters
	void setID(string ID);
	void setFirstName(string firstname);
	void setLastName(string lastname);
	void setEmailAddress(string emailaddress);
	void setAge(int age);
	void setCourses(double courses[]);
	void setDegreeType(DegreeType dt);

	static void printHeader();

	void print();
};
#endif // STUDENT_H

