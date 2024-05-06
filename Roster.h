#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include "Student.h"
#include "degree.h"
#include <iostream>
class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string row);
	void add(string sID,
		string sFirstName,
		string sLastName,
		string sEmailAddress,
		int sAge,
		double sCourse1,
		double sCourse2,
		double sCourse3,
		DegreeType dt);
	Student** getRosterArray();
	int getLastIndex() const;
	void printAll();
	void printByDegreeType(DegreeType dt); //Degree type is passed
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void removeStudentByID(string studentID);
	~Roster();
};
#endif // ROSTER_H


