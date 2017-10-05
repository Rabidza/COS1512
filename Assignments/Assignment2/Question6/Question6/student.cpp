//Implementation file student.cpp:
//This is the IMPLEMENTATION of the ADT Student.
//The interface for the class Student is in the header file student.h.
#include "student.h"
#include <cstring>
#include <sstream>
using namespace std;

Student::Student() : name(""), diploma(""), ID(0), studentNumber(0), average(0)
{
    //Intentionally left empty
}

Student::Student(string StudentName, int StudentID, int StudentNumber, string StudentDiploma)
    : name(StudentName), ID(StudentID), studentNumber(StudentNumber), diploma(StudentDiploma)
{
    //Intentionally left empty
}


Student::~Student()
{
    //I think you're looking for a delete[] arrayName line in here, but I'm not using the new keyword.
    cout << "Bye!";
}

double Student::calcAverage()
{
    double total = 0;
    for (int i = 0; i < NUM_MODULES; i++)
    {
        total += results[i];
    }

    return total / NUM_MODULES;
}

bool Student::pass()
{
    for (int i = 0; i < NUM_MODULES; i++)
    {
        if (results[i] < 50)
            return false;
    }
    return true;
}

void Student::displayResults()
{
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        cout << "Student Name:   " << name << endl;
        cout << "Student Number: " << studentNumber << endl;
        cout << "Diploma:        " << diploma << endl;
        for (int j = 0; j < NUM_MODULES; j++)
        {
            cout << "Module: " << modules[j] << "\tResult: " << results[i] << endl;
        }
        cout << "Average:        " << getAverage();
        cout << "Pass:           " << pass();
    }
}

void Student::setName(string StudentName)
{
    name = StudentName;
}

void Student::setID(int StudentID)
{
    ID = StudentID;
}

void Student::setStudentNumber(int StudentNumber)
{
    studentNumber = StudentNumber;
}

void Student::setDiploma(string StudentDiploma)
{
    diploma = StudentDiploma;
    if (StudentDiploma == "Garden Design")
    {
        for (int i = 0; i < 5; i++)
        {
            stringstream nextvalue;
            nextvalue << (i + 1);
            modules[i] = "G" + nextvalue.str();
        }
    }
    else if (StudentDiploma == "Gourmet Cooking")
    {
         for (int i = 0; i < 5; i++)
        {
            stringstream nextvalue;
            nextvalue << (i + 1);
            modules[i] = "C" + nextvalue.str();
        }
    }
}

void Student::setAverage(int StudentMark)
{
    average = StudentMark;
}

void Student::setMark(int module, int mark)
{
    results[module] = mark;
}

string Student::getName()
{
    return name;
}

int Student::getID()
{
    return ID;
}

int Student::getStudentNumber()
{
    return studentNumber;
}

string Student::getDiploma()
{
    return diploma;
}

double Student::getAverage()
{
    return average;
}

string Student::getModule(int i)
{
    return modules[i];
}

ostream& operator <<(ostream& outs, const Student& theObject)
{
    outs << "\nStudent Name:   " << theObject.name
         << "\nStudent ID:     " << theObject.ID
         << "\nStudent Number: " << theObject.studentNumber
         << "\nCourse:         " << theObject.diploma << endl;
}

istream& operator >>(istream& ins, Student& theObject)
{
    cout << "Enter the Student Name: ";
    getline(ins, theObject.name, '\n');
    cout << "Enter the Student ID: ";
    cin >> theObject.ID;
    cout << "Enter the Student Number: ";
    cin >> theObject.studentNumber;
    cin.get();
    cout << "Enter the Diploma: ";
    getline(ins, theObject.diploma, '\n');
    cout << endl;
}

