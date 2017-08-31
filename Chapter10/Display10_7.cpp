//Demonstrate an alternative implementation of the class BankAccount.
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//Class for a bank account:
class BankAccount
{
public:
    BankAccount(int dollars, int cents, double rate);
    //Initializes the account balance to $dollars.cents and
    //initializes the interest rate to rate percent.

    BankAccount(int dollars, double rate);
    //Initializes the account balanace to $dollars.00 and
    //initializes the interest rate to rate percent.

    BankAccount();
    //Initializes the account balance to $0.00 and the
    //interest rate to 0.0%

    void set(int dolalrs, int cents, double rate);
    //Postcondition: The account balance has been set to $dollars.cents;
    //The interest rate has been set to rate percent.

    void set(int dollars, double rate);
    //Postcondition: The account balanace has been set to $dollars.00
    //The interest rate has been set to rate percent.

    void update();
    //Postcondition: One year of simple interest has been
    //added to the account balance.

    double get_balance();
    //Returns the current account balance.

    double get_rate();
    //Returns the current account interest rate as a percentage.

    void output(ostream& outs);
    //Precondition: If outs is a file output stream, then
    //outs has already been connected to a file.
    //Postcondition: Account balance and interest rate
    //have been written to the stram outs.

private:
    int dollars_part;
    int cents_part;
    double interest_rate; //Expressed as a fraction, for example, 0.057 for 5.7%

    double fraction(double percent);
    //Converts a percentage to a fraction. For example, fraction (50.3)
    //returns 0.503.

    double percent(double fraction_value);
    //Converts a fraction to a percentage. For example, percent (0.503)
    //returns 50.3.
};

int main()
{
    BankAccount account1(100, 2.3), account2;

    cout << "account1 initialized as follows:\n";
    account1.output(cout);
    cout << "account2 initialized as follows:\n";
    account2.output(cout);

    account1 = BankAccount(999, 99, 5.5);
    cout << "account1 reset to the following:\n";
    account1.output(cout);

    return 0;
}

BankAccount::BankAccount(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interest rate.\n";
        exit(1);
    }

    dollars_part = dollars;
    cents_part = cents;
    interest_rate = fraction(rate);
}

BankAccount::BankAccount(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interest rate.\n";
        exit(1);
    }

    dollars_part = dollars;
    cents_part = 0;
    interest_rate = fraction(rate);
}

BankAccount::BankAccount() : dollars_part(0), cents_part(0), interest_rate(0.0)
{
    //Body intentionally empty.
}

double BankAccount::fraction(double percent_value)
{
    return (percent_value/100.0);
}

//Uses cmath:
void BankAccount::update()
{
    double balance = get_balance();
    balance = balance + interest_rate * balance;
    dollars_part = static_cast<int>(floor(balance));
    cents_part = static_cast<int>(floor((balance - dollars_part)*100));
}

double BankAccount::get_balance()
{
    return (dollars_part + 0.01 * cents_part);
}

double BankAccount::percent(double fraction_value)
{
    return (fraction_value * 100);
}

double BankAccount::get_rate()
{
    return percent(interest_rate);
}

//Uses iostream:
void BankAccount::output(ostream& outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << get_balance() << endl;
    outs << "Interest rate " << get_rate() << "%" << endl;
}

void BankAccount::set(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interest rate.\n";
        exit(1);
    }

    dollars_part = dollars;
    cents_part = cents;
    interest_rate = fraction(rate);
}

void BankAccount::set(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interest rate.\n";
        exit(1);
    }

    dollars_part = dollars;
    interest_rate = fraction(rate);
}
