//Program to demonstrate the class BankAccount.
#include <iostream>
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
    //Initializes the account balance to $dollars.00 and
    //initializes the interest rate to rate percent.

    BankAccount();
    //Initializes the account balance to $0.00
    //and the interest rate to 0.0%.

    void set(int dollars, int cents, double rate);
    //Postcondition: The account balance has been set to $dollars.cents;
    //The interest rate has been set to rate percent.

    void set(int dollars, double rate);
    //Postcondition: The account balance has been set to $dollars.00.
    //The interest rate has been set to rate percent.

    void update();
    //Postcondition: One year of simple interest has been added
    //to the account balance.

    double get_balance();
    //Returns the current account interest rate as a percentage.

    double get_rate();
    //Returns the current account interest rate as a percentage.

    void output(ostream& outs);
    //Precondition: If outs is a file output stream, then
    //outs has already been connected to a file.
    //Postcondition: Account balance and interest rate
    //have been written to the stream outs.

private:
    double balance;
    double interest_rate;

    double fraction(double percent);
    //Converts a percentage to a fraction. For example, fraction(50.3)
    //returns 0.503.
};

BankAccount::BankAccount(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interest rate.\n";
        exit(1);
    }

    balance = dollars + 0.01 * cents;
    interest_rate = rate;
}

BankAccount::BankAccount(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interest rate.\n";
        exit(1);
    }

    balance = dollars;
    interest_rate = rate;
}

BankAccount::BankAccount() : balance(0), interest_rate(0.0)
{
    //Body intentionally empty
}

void BankAccount::update()
{
    balance = balance + fraction(interest_rate)*balance;
}

double BankAccount::fraction(double percent_value)
{
    return (percent_value / 100.0);
}

double BankAccount::get_balance()
{
    return balance;
}

double BankAccount::get_rate()
{
    return interest_rate;
}

//Uses iostream:
void BankAccount::output(ostream& outs)
{
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << balance << endl;
    outs << "Interest rate " << interest_rate << "%" << endl;
}

void BankAccount::set(int dollars, int cents, double rate)
{
    if ((dollars < 0) || (cents < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interest rate.\n";
        exit(1);
    }

    balance = dollars + 0.01*cents;
    interest_rate = rate;
}

void BankAccount::set(int dollars, double rate)
{
    if ((dollars < 0) || (rate < 0))
    {
        cout << "Illegal values for money or interest rate.\n";
        exit(1);
    }

    balance = dollars;
    interest_rate = rate;
}

class SavingsAccount : public BankAccount
{
public:
    SavingsAccount(int dollars, int cents, double rate);
    //Other constructors would go here

    void deposit(int dollars, int cents);
    //Adds $dollars.cents to the account balance.

    void withdraw(int dollars, int cents);
    //Subtracts $dollars.cents from the account balance.

private:

};

int main()
{
    SavingsAccount account(100, 50, 5.5);
    account.output(cout);
    cout << endl;

    cout << "Depositing $10.25." << endl;
    account.deposit(10, 25);
    account.output(cout);
    cout << endl;

    cout << "Withdrawing $11.80." << endl;
    account.withdraw(11, 80);
    account.output(cout);
    cout << endl;

    return 0;
}

SavingsAccount::SavingsAccount(int dollars, int cents, double rate):
    BankAccount(dollars, cents, rate)
{
    //deliberately empty
}

void SavingsAccount::deposit(int dollars, int cents)
{
    double balance = get_balance();
    balance += dollars;
    balance += (static_cast<double>(cents) / 100);
    int new_dollars = static_cast<int>(balance);
    int new_cents = static_cast<int>((balance - new_dollars) * 100);
    set(new_dollars, new_cents, get_rate());
}

void SavingsAccount::withdraw(int dollars, int cents)
{
    double balance = get_balance();
    balance -= dollars;
    balance -= (static_cast<double>(cents) / 100);
    int new_dollars = static_cast<int>(balance);
    int new_cents = static_cast<int>((balance - new_dollars) * 100);
    set(new_dollars, new_cents, get_rate());
}
