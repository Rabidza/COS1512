//Demonstration program for improved version of get_int.
#include <iostream>
#include <cstdlib>
#include <cctype>

void read_and_clean(int& n);
//Reads a line of input. Discards all symbols except the digits. Converts
//the C string to an integer and sets n equal to the value of this integer.

void new_line();
//Discards all the input remaining on the current input line.
//Also discards the '\n' at the end of the line.

void get_int(int& input_number);
//Gives input_number a value that the user approves of.

int main()
{
    using namespace std;
    int input_number;
    get_int(input_number);
    cout << "The final value read in = " << input_number << endl;

    return 0;
}

//Uses iostream and read_and_clean:
void get_int(int& input_number)
{
    using namespace std;
    char ans;
    do
    {
        cout << "Enter input number: ";
        read_and_clean(input_number);
        cout << "You entered " << input_number
             << " Is that correct? (yes/no): ";
        cin >> ans;
        new_line();
    } while ((ans != 'y') && (ans != 'Y'));
}

//Uses iostream, cstdlib, and cctype:
void read_and_clean(int& n)
{
    using namespace std;
    const int ARRAY_SIZE = 6;
    char digit_string[ARRAY_SIZE];

    char next;
    cin.get(next);
    int index = 0;
    while (next != '\n')
    {
        if ((isdigit(next)) && (index < ARRAY_SIZE - 1))
        {
            digit_string[index] = next;
            index++;
        }
        cin.get(next);
    }
    digit_string[index] = '\0';
    n = atoi(digit_string);
}

//Uses iostream:
void new_line()
{
    using namespace std;
    char symbol;
    do
    {
        cin.get(symbol);
    } while (symbol != '\n');
}
