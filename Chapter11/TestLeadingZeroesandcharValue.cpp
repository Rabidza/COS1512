#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char c;
    int answer;

    //char value test
    cout << "Enter a number: ";
    cin >> c;

    cout << "The char value is: ";
    cout << c << endl;

    cout << "The int value is: ";
    cout << (static_cast<int>(c)) << endl;

    cout << "The correct value is: ";
    cout << (static_cast<int>(c) - static_cast<int>('0')) << endl;


    //Leading Zero test
    cout << "Enter a value with a leading zero: ";
    cin >> answer;
    cout << answer << endl;

    return 0;

}
