//Program to demonstrate the function equal. The class DayOfYear
//is the same as in Self-Test Exercises 23-24 in Chapter 10.
#include <iostream>
#include <cstdlib>
using namespace std;

class DayOfYear
{
public:
    DayOfYear(int the_month, int the_day);
    //Precondition: the_month and the_day from a
    //possible date. Initializes the date according
    //to the arguments.

    DayOfYear();
    //Initializes the date to January first.

    void input();

    void output();

    int get_month();
    //Returns the month, 1 for January, 2 for February, etc.

    int get_day();
    //Returns the day of the month.

private:
    void check_date();
    int month;
    int day;
};

bool equal(DayOfYear date1, DayOfYear date2);
//Precondition: date1 and date2 have values.
//Returns true if date1 and date2 represent the same date;
//otherwise, returns false.

int main()
{
    DayOfYear today, bach_birthday(3, 21);

    cout << "Enter today's date:\n";
    today.input();
    cout << "Today's date is ";
    today.output();

    cout << "J.S. Bach's birthday is ";
    bach_birthday.output();

    if (equal(today, bach_birthday))
        cout << "Happy Birthday Johann Sebastian!\n";
    else
        cout << "Happy Unbirthday Johann Sebastian!\n";

    return 0;
}

bool equal(DayOfYear date1, DayOfYear date2)
{
    return (date1.get_month() == date2.get_month() &&
            date1.get_day() == date2.get_day());
}

DayOfYear::DayOfYear(int the_month, int the_day)
    : month(the_month), day(the_day)
{
    check_date();
}

DayOfYear::DayOfYear(): month(1), day(1)
{
    //Body intentionally empty.
}

int DayOfYear::get_month()
{
    return month;
}

int DayOfYear::get_day()
{
    return day;
}

//Uses iostream:
void DayOfYear::input()
{
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
}

//Uses iostream:
void DayOfYear::output()
{
    cout << "month = " << month
         << ", day = " << day << endl;
}

void DayOfYear::check_date( )
{
    if ((month < 1) || (month > 12) || (day < 1) || (day > 31))
    {
        cout << "Illegal date. Aborting program.\n";
        exit(1);
    }
}
