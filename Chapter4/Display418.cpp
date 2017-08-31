//Determines whether a round pizza or rectangular pizza is the buy.
#include <iostream>

double unitprice(int diameter, double price);
//Returns the price per square inch of a round pizza.
//The formal parameter named diameter is the diameter of the pizza
//in inches. The formal parameter named price is the price of the pizza.

double unitprice(int length, int width, double price);
//Returns the price per square inch of a rectangular pizza
//with dimensions length by width inches.
//The formal parameter price is the price of the pizza.

int main()
{
    using namespace std;
    int diameter, length, width;
    double price_round, unit_price_round,
    price_rectangular, unit_price_rectangular;

    cout << "Welcome to the Pizza Consumers Union.\n";
    cout << "Enter the diameter in inches"
         << " of a round pizza: ";
    cin >> diameter;
    cout << "Enter the price of a round pizza: $";
    cin >> price_round;
    cout << "Enter the length and width in inches\n"
         << "of a rectangular pizza: ";
    cin >> length >> width;
    cout << "Enter the price of a rectangular pizza: $";
    cin >> price_rectangular;

    unit_price_rectangular =
                unitprice(length, width, price_rectangular);
    unit_price_round = unitprice(diameter, price_round);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << endl
         << "Round pizza: Diameter = "
         << diameter << " inches\n"
         << "Price = $" << price_round
         << " Per square inch = $" << unit_price_round
         << endl
         << "Rectangular pizza: Length = "
         << length << " inches\n"
         << "Rectangular pizza: Width = "
         << width << " inches\n"
         << "Price = $" << price_rectangular
         << " Per square inch = $" << unit_price_rectangular
         << endl;

    if (unit_price_round < unit_price_rectangular)
        cout << "The round one is the better buy.\n";
    else
        cout << "The rectangular one is the better buy.\n";

    cout << "Buon Appetito!";
    return 0;
}

double unitprice(int diameter, double price)
{
    const double PI = 3.14159;
    double radius, area;

    radius = diameter/static_cast<double>(2);
    area = PI * radius * radius;
    return (price/area);
}

double unitprice(int length, int width, double price)
{
    double area = length * width;
    return (price/area);
}
