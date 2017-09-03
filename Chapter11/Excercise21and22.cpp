//This is a definition for the class
//Temperaturelist. Values of this type are lists of Fahrenheit temperatures.
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_LIST_SIZE = 50;

class TemperatureList
{
public:
    TemperatureList();
    //Initializes the object to an empty list.

    int get_size() const;
    //Returns the number of temperatures in the list.

    void add_temperature(double temperature);
    //Precondition: The list is not full.
    //Postcondition: The temperature has been added to the list.

    double get_temperature(int position) const;
    //Precondition: 0 <= position < get_size().
    //Returns the temperature that was added in position
    //specified. The first temperature that was added is
    //in position 0.

    bool full() const;
    //Returns true if the list is full; false otherwise.

    friend ostream& operator <<(ostream& outs,
                                const TemperatureList& the_object);
    //Overloads the << operator so it can be used to output values of
    //type TemperatureList. Temperatures are output one per line.
    //Precondition: If outs is a file output stream, then outs
    //has already been connected to a file.

private:
    double list[MAX_LIST_SIZE]; //of temperatures in Fahrenheit
    int size; //number of array positions filled
};

int main()
{
    return 0;
}

//This is the implementation for the class TemperatureList.
TemperatureList::TemperatureList() : size(0)
{
    //Body intentionally empty.
}

int TemperatureList::get_size() const
{
    return size;
}

//Uses iostream and cstdlib:
void TemperatureList::add_temperature(double temperature)
{
    if (full())
    {
        cout << "Error: adding to a full list.\n";
        exit(1);
    }
    else
    {
        list[size] = temperature;
        size = size + 1;
    }
}

//Uses iostream and cstdlib:
double TemperatureList::get_temperature(int position) const
{
    if ((position >= size) || (position < 0))
    {
        cout << "Error: reading an empty list position.\n";
        exit(1);
    }
    else
        return (list[position]);
}

bool TemperatureList::full() const
{
    return (size == MAX_LIST_SIZE);
}

//Uses iostream:
ostream& operator <<(ostream& outs, const TemperatureList& the_object)
{
    for (int i = 0; i < the_object.size; i++)
        outs << the_object.list[i] << " F\n";

    return outs;
}

