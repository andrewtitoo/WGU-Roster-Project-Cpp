#include "Roster.h"
#include "degree.h"
#include <iostream>

int main()
{
    // Print information about the program
    std::cout << "Course Title: Scripting and Programming: Applications\n"
        << "Programming Language: C++\n"
        << "WGU Student ID: 011646949\n"
        << "Name: Andrew Titoian\n\n";

    // Create an instance of the Roster class
    Roster classRoster;

    // Add each student to classRoster
    const string studentData[] = {
        "A1, John, Smith, John1989@gm ail.com, 20, 30, 35, 40, SECURITY",
        "A2, Suzan, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
        "A3, Jack, Napoli, The_lawyer99yahoo.com, 19, 20, 40, 33, SOFTWARE",
        "A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
        "A5, Andrew, Titoian, Atitoia@wgu.edu, 20, 10, 20, 14, SOFTWARE"
    };

    for (const auto& data : studentData)
    {
        classRoster.parse(data);
    }

    // Display requested information
    std::cout << "Displaying all Students:\n";
    classRoster.printAll();

    std::cout << "\nDisplaying Students with Invalid Emails:\n";
    classRoster.printInvalidEmails();

    // Loop through classRosterArray and print average days in courses
    Student** rosterArray = classRoster.getRosterArray();
    for (int i = 0; i <= classRoster.getLastIndex(); ++i)
    {
        std::cout << "\nDisplaying average days in Courses for Student ID " << rosterArray[i]->getID() << ":\n";
        classRoster.printAverageDaysInCourse(rosterArray[i]->getID());
    }

    // Print by degree program and remove students
    std::cout << "\nDisplaying Students with Degree Program: SOFTWARE\n";
    classRoster.printByDegreeType(SOFTWARE);

    std::cout << "\nRemoving student with ID A3:\n";
    classRoster.removeStudentByID("A3");

    // Try to remove a non-existing student
    std::cout << "\nRemoving non-existing student with ID A3:\n";
    classRoster.removeStudentByID("A3");

    // Display the updated roster
    std::cout << "\nDisplaying all Students after removals:\n";
    classRoster.printAll();

    return 0;
}

