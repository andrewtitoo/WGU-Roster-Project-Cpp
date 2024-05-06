#include "Student.h"
#include "degree.h"
#include "Roster.h"
#include <iostream>

using std::string;
using std::cout;

//parameterless constructor
Student::Student()
{
	this->studentID = "";
	this->firstname = "";
	this->lastname = "";
	this->emailaddress = "";
	this->age = 0;
	for (int i = 0; i < courseArraySize; i++) this->courses[i] = 0;
	this->degreeType = DegreeType::SECURITY;
}

//constructor
Student::Student(string studentID, string firstname, string lastname, string emailaddress, int age, double courses[], DegreeType degreeType)
{
	this->studentID = studentID;
	this->firstname = firstname;
	this->lastname = lastname;
	this->emailaddress = emailaddress;
	this->age = age;
	for (int i = 0; i < courseArraySize; i++) this->courses[i] = courses[i];
	this->degreeType = degreeType;
}
//destructor
Student::~Student() {}

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstname; }
string Student::getLastName() { return this->lastname; }
string Student::getEmailAddress() { return this->emailaddress; }
int Student::getAge() { return this->age; }
double* Student::getCourses() { return this->courses; }
DegreeType Student::getDegreeType() const { return this->degreeType; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirstName(string firstname) { this->firstname = firstname; }
void Student::setLastName(string lastname) { this->lastname = lastname; }
void Student::setEmailAddress(string emailaddress) { this->emailaddress = emailaddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setCourses(double courses[])
{
	for (int i = 0; i < courseArraySize; i++) this->courses[i] = courses[i];
}
void Student::setDegreeType(DegreeType dt) { this->degreeType = dt; }


//print header
void Student::printHeader()
{
	cout << "Output format: ID | First Name | Last Name | Email Address | Age | Courses | Degree Type\n";
}

void Student::print()
{
	cout << this->getID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getCourses()[0] << ',';
	cout << this->getCourses()[1] << ',';
	cout << this->getCourses()[2] << '\t';
	cout << DegreeTypeStrings[this->getDegreeType()] << '\n';
}

