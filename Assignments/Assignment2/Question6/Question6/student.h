//Header file student.h: This is the interface for the class Team
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int NUM_MODULES = 5;
const int NUM_STUDENTS = 3;

class Student
{
public:
    Student();
    //Initializes name, diploma to "" and ID, studentNumber and average to 0.

    Student(string StudentName, int StudentID, int StudentNumber, string Studentdiploma);
    //Initializes the student values

    ~Student();
    //Destructor which also outputs "Bye!" when called

    double calcAverage();
    //Calculate the average for the five results.

    bool pass();
    //Ddetermines whether or not a student has passed the module
    //A student only passes a diploma course if he or she has obtained more than 50% for all the modules,
    //regardless of his or her average mark. Member function pass()should return a boolean value.

    void displayResults();
    //Display a student’s results.
    //Member function displayResults() display a student’s name, student number, name of the diploma registered for,
    //his or her results for each module, the average mark and whether he or she passed or failed the diploma.

    void setName(string StudentName);
    //Sets the name to StudentName.

    void setID(int StudentID);
    //Sets the ID to StudentID.

    void setStudentNumber(int StudentNumber);
    //Sets the studentNumber to StudentNumber.

    void setDiploma(string StudentDiploma);
    //Sets the diploma to StudentDiploma.
    //Also sets the module names automatically.

    void setAverage(int StudentMark);
    //Sets the average to StudentMark.

    void setMark(int module, int mark);
    //Sets the mark of the module.

    string getName();
    //Returns the name.

    int getID();
    //Returns the ID.

    int getStudentNumber();
    //Returns the studentNumber.

    string getDiploma();
    //Returns the diploma.

    double getAverage();
    //Returns the average.

    string getModule(int i);
    //Returns the name of the module.

    friend ostream& operator <<(ostream& outs, const Student& theObject);
    //Precondition: If outs is a file output stream, then outs
    //has already been connected to a file.
    //Overloads the << operator so it can be used to display
    //values for all the member variables of class Student

    friend istream& operator >>(istream& ins, Student& theObject);
    //Precondition: If ins is a file intput stream, then ins
    //has already been connected to a file.
    //Overloads the >> operator for input values of type Student
    //values for all the member variables of class Student

private:
    string name, diploma, modules[NUM_MODULES];
    int ID, studentNumber, results[NUM_MODULES];
    double average;

};

#endif // STUDENT_H
