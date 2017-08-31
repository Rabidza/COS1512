//Program to demonstrate the class Money
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

//Clas for amounts of money in U.S currency.
class Money
{
public:
    friend Money add(Money amount1, Money amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns true if the amount1 and amount2 have the same value;
    //otherwise, returns false.

    Money(long dollars, int cents);
    //Initializes the object so its value represents an aount with the
    //dollars and cents given by the arguments. If the amount is negative,
    //then both dollars and cents must be negative.

    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.

    Money();
    //Initializes the object so its value represents $0.00

    double get_value();
    //Precondition: The calling object has been given a value.
    //Returns the amount of money recorded in the data of the calling object.
};
