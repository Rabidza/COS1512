#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    Employee();
    // Initializes the employee‘s first name and last name to a blank string, and his annual salary to 0.

    Employee(string name, string surname, float AnnualSalary);
    //Initializes the Employee with name, surname and AnnualSalary.

    void setFirstName(string name);
    //Postcondition: The employee firstName is set to name.

    void setLastName(string surname);
    //Postcondition: The employee lastName is set to surnname.

    void setSalary(float annualSalary);
    //Postcondition: The employee salary is set to annualSalary.

    string getFirstName();
    //Returns the first name of the employee.

    string getLastName();
    //Returns the last name of the employee.

    float getSalary();
    //Returns salary of the employee.

private:
    string firstName;
    string lastName;
    float salary;
};

int main()
{
    string name, surname;
    float annualSalary;
    Employee employee1("Joe", "Soap", 1456.00);

    cout << "Enter the name of the employee: ";
    getline(cin, name, '\n');
    cout << "Enter the surname of the employee: ";
    getline(cin, surname, '\n');
    cout << "Enter the employee salary: ";
    cin >> annualSalary;
    Employee employee2(name, surname, annualSalary);

    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << endl;

    cout << "The first employee is: "
         << employee1.getFirstName() << " " << employee2.getLastName() << endl
         << "Annual salary: R" << employee1.getSalary() << endl << endl;

    cout << "The second employee is: "
         << employee2.getFirstName() << " " << employee2.getLastName() << endl
         << "Annual salary: R" << employee2.getSalary() << endl << endl;

    employee1.setSalary(employee1.getSalary() * 10 / 100 + employee1.getSalary());
    employee2.setSalary(employee1.getSalary() * 10 / 100 + employee2.getSalary());

    cout << "After a 10% increase: " << endl;
    cout << employee1.getFirstName() << " " << employee1.getLastName() << endl;
    cout << "Now earns : R" << employee1.getSalary() << " a year." << endl << endl;
    cout << "and: " << endl;
    cout << employee2.getFirstName() << " " << employee2.getLastName() << endl;
    cout << "Now earns : R" << employee2.getSalary() << " a year." << endl << endl;

    return 0;
}

Employee::Employee() : firstName(""), lastName(""), salary(0.0)
{
    //Body intentionally empty
}

Employee::Employee(string name, string surname, float pay)
{
    firstName = name;
    lastName = surname;
    salary = pay;
}

void Employee::setFirstName(string name)
{
    firstName = name;
}

void Employee::setLastName(string surname)
{
    lastName = surname;
}

void Employee::setSalary(float AnnualSalary)
{
    salary = AnnualSalary;
}


string Employee::getFirstName()
{
    return firstName;
}

string Employee::getLastName()
{
    return lastName;
}

float Employee::getSalary()
{
    return salary;
}
