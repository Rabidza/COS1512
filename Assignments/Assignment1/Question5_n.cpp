#include <iostream>
using namespace std;

int main()
{
    int numStudents;
    int totalScore;
    double averageScore;

    cout << "Please enter the number of students: ";
    cin >> numStudents;

    double* scores;
    scores = new double [numStudents];
    cout << "Enter the score for each student.\n";
    totalScore = 0;
    for (int index = 0; index < numStudents; index++)
    {
        cin >> scores[index];
        totalScore += scores[index];
    }

    averageScore = totalScore / (double)numStudents;
    cout << "The average score is: " << averageScore;

    delete [] scores;

    return 0;
}
