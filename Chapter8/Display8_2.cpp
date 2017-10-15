//Demonstrates the functino read_and_clean.
#include <iostream>
#include <cstdlib>
#include <cctype>

void read_and_clean(int& n);
//Reads a line of input. Discards all symbols except the digits. Converts
//the C string to an integer and sets n equal to the value of this integer.

void new_line();
//Discards all the input remaining on the current input line.
//Also discards the '\n' at the end of the line.

int main()
{
    using namespace std;
    int n;
    char ans;

    do
    {
        cout << "Enter an integer and press Return: ";
        read_and_clean(n);
        cout << "The string converts to the integer " << n << endl;
        cout << "Again? (yes/no): ";
        cin >> ans;
        new_line();
    } while ((ans != 'n') && (ans != 'N'));

    return 0;
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
