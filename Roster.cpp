#include "Roster.h"
#include "degree.h"
#include "Student.h"
#include <iostream>

void Roster::parse(string classRoster)
{
    DegreeType dt = SECURITY;

    //Extract the degree type 
    size_t pos = classRoster.rfind(",") + 1;
    string DegreeTypeStrings = classRoster.substr(pos);

    if (DegreeTypeStrings.find("SECURITY") != string::npos)
    {
        dt = SECURITY;
    }
    else if (DegreeTypeStrings.find("NETWORK") != string::npos)
    {
        dt = NETWORK;
    }
    else if (DegreeTypeStrings.find("SOFTWARE") != string::npos)
    {
        dt = SOFTWARE;
    }
    //find and parse student data
    int rhs = classRoster.find(",");
    string sID = classRoster.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = classRoster.find(",", lhs);
    string first = classRoster.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = classRoster.find(",", lhs);
    string last = classRoster.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = classRoster.find(",", lhs);
    string email = classRoster.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = classRoster.find(",", lhs);
    int age = stoi(classRoster.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = classRoster.find(",", lhs);
    double c1 = stod(classRoster.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = classRoster.find(",", lhs);
    double c2 = stod(classRoster.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = classRoster.find(",", lhs);
    double c3 = stod(classRoster.substr(lhs, rhs - lhs));


    add(sID, first, last, email, age, c1, c2, c3, dt);
};

//add method
void Roster::add(string studentID, string firstname, string lastname, string emailaddress, int age, double course1, double course2, double course3, DegreeType dt)
{
    //place days in course into an array 
    double parr[3] = { course1, course2, course3 };

    //Use full constructor

    classRosterArray[++lastIndex] = new Student(studentID, firstname, lastname, emailaddress, age, parr, dt);
}

void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        classRosterArray[i]->print();
    }
}

void Roster::printByDegreeType(DegreeType dt)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (Roster::classRosterArray[i]->getDegreeType() == dt) classRosterArray[i]->print();
    }
    cout << std::endl;
}

void Roster::printInvalidEmails()
{
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string sEmailAddress = classRosterArray[i]->getEmailAddress();
        if (sEmailAddress.find('@') == string::npos || (sEmailAddress.find('.') == string::npos))
        {
            any = true;
            cout << sEmailAddress << ": " << classRosterArray[i]->getFirstName() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}
Student** Roster::getRosterArray()
{
    return classRosterArray;
}

int Roster::getLastIndex() const
{
    return lastIndex;
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            double averageDays = (classRosterArray[i]->getCourses()[0]
                + classRosterArray[i]->getCourses()[1]
                + classRosterArray[i]->getCourses()[2])
                / 3.0;
            cout << "Average days in course for student with ID '" << studentID << "': " << averageDays << std::endl;
            return;

        }
    }
    cout << "Student with ID '" << studentID << "' not found." << std::endl;
}



void Roster::removeStudentByID(string studentID)
{
    bool removal = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            removal = true;
            if (i < numStudents - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (removal)
    {
        cout << studentID << " was removed from roster." << std::endl << std::endl;
        this->printAll();

    }
    else
    {
        cout << studentID << " was not found." << std::endl << std::endl;

    }
}

Roster::~Roster()
{
    cout << "Destructor Initiated" << std::endl << std::endl;
    for (int i = 0; i < numStudents; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            cout << "Removing Student #" << i + 1 << std::endl;
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}
