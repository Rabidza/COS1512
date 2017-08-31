#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void getTime(int &hoursP, int &minutesP, int &secondsP)
{
    cout << "Please enter time (hh mm ss): ";
    cin >> hoursP >> minutesP >> secondsP;
    assert(hoursP < 24 && hoursP >= 0);
    assert(minutesP < 60 && minutesP >= 0);
    assert(secondsP < 60 && secondsP >= 0);
}

int timeToSeconds(int hoursP, int mintuesP, int secondsP)
{
    return (hoursP * 60 * 60) + (mintuesP * 60) + secondsP;

}

int subtractSeconds(int seconds1P, int seconds2P)
{
    if (seconds1P > seconds2P)
        return seconds1P - seconds2P;
    else
        return seconds2P - seconds1P;
}

void secondsToTime(int differenceP)
{
    int hours, minutes, seconds;

    minutes = differenceP / 60;
    hours = minutes / 60;

    cout << "The time difference is: " << endl;
    cout.fill('0');
    cout.width( 2 );
    cout << hours << ":";
    cout.fill('0');
    cout.width( 2 );
    cout << minutes % 60 << ":";
    cout.fill('0');
    cout.width( 2 );
    cout << differenceP % 60 << endl;
}

int main()
{
    int hours, minutes, seconds, secondsA, secondsB, difference;

    getTime(hours, minutes, seconds);
    secondsA = timeToSeconds(hours, minutes, seconds);
    getTime(hours, minutes, seconds);
    secondsB = timeToSeconds(hours, minutes, seconds);

    difference = subtractSeconds(secondsA, secondsB);
    secondsToTime(difference);

    return 0;
}
