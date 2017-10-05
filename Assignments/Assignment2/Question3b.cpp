#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person();
    // Initializes the employee‘s first name and last name to a blank string, and his annual salary to 0.

    Person(string name);
    //Initializes the Employee with name, surname and AnnualSalary.

    string getName();
    //Returns the first name of the employee.

private:
    string firstName;
};

int main()
{
    Person me, friends[10];
    for (int i = 0; i < 10; i++)
    {
        if (me.getName() == friends[i].getName())
        cout << "My friend no " << i
        << " has the same first name as me!";
    }
}

Person::Person() : firstName("Neill")
{
    //Body intentionally empty
}

Person::Person(string name)
{
    firstName = name;
}

string Person::getName()
{
    return firstName;
}
