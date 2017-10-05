#include <iostream>
#include <fstream>
#include <cstdlib>
#include "student.h"

using namespace std;

int main()
{
    Student students[NUM_STUDENTS];

    ofstream fout;
    fout.open("RegisteredStudentsResults.dat", ios::app);
    if (fout.fail( ))
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        cin >> students[i];
        students[i].setDiploma(students[i].getDiploma());
    }

    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        cout << students[i];
        for (int j = 0; j < NUM_MODULES; j++)
        {
            string currentModule = students[i].getModule(j);
            int currentMark;
            cout << "Enter the results of the module: " << currentModule << " : ";
            cin >> currentMark;
            students[i].setMark(j, currentMark);
        }
        students[i].setAverage(students[i].calcAverage());

        fout << students[i];
    }

    fout.close();

    for (int i = 0; i < NUM_STUDENTS; i++)
        cout << students[i];

    return 0;
}
