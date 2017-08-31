#include <iostream>
#include <iomanip>
using namespace std;

double getPrize(int ticketNumP, char genderP)
{
    if (genderP == 'm' && ticketNumP > 30000)
        return ticketNumP / 90.00;
    else if (genderP == 'f' && ticketNumP > 20000)
        return ticketNumP / 80.00;
    else
        return 0;
}

double getPrize(int ticketNumP, int ageP)
{
    if (ageP <= 21)
        return ageP * 40.00;
    else if (ageP > 21 )
        return ageP * 30.00;
    return 0; //Will never return this
}

int main()
{
    int ticketNum, age;
    char gender;
    double prize = 0;

    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "Please enter your ticket number: ";
    cin >> ticketNum;

    if (ticketNum % 100 == 0)
    {
        cout << "Please enter your sex (m)ale/(f)emale: ";
        cin >> gender;
        prize = getPrize(ticketNum, gender);
    }
    else if(ticketNum % 7 == 0 && ticketNum % 6 == 0)
    {
        cout << "Please enter your age: ";
        cin >> age;
        prize = getPrize(ticketNum, age);
    }

    if (prize == 0)
        cout << "You don't have a winning ticket :(" << endl;
    else
    {
        cout << "Congratulations you are a winner!!" << endl;
        cout << "You have won: R" << prize << endl;
    }

    return 0;
}
