//Illustrates output formatting instructions
//Reads all the numbers in the file rawdata.dat and writes the numbers
//to the screen and to the file neat.dat in a neatly formatted way
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;
void make_neat(ifstream& messy_file, ofstream& neat_file,
               int number_after_decimalpoint, int field_width);
//Precondition: The streams messy_file and neat_file have been connected
//to files using the function open.
//Postcondition: The numbers in the file connected to messy_file have been
//written to the screen and to the file connected to the stream neat_file.
//The numbers are written one per line, in fixed-point notation (that is, not in
//e-notation), with number_after_decimalpoint digits after the decimal point;
//each number is preceded by a plus or a minus sign and each number is in a field
//of width field_width. (This function does not close the file.)
int main()
{
    ifstream fin;
    ofstream fout;

    fin.open("rawdata.dat");
    if (fin.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    fout.open("neat.dat");
    if (fout.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    make_neat(fin, fout, 5, 12);

    fin.close();
    fout.close();

    cout << "End of program.\n";
    return 0;
}

//Uses iostream, fstream and iomanip:
void make_neat(ifstream& messy_file, ofstream& neat_file,
               int number_after_decimalpoint, int field_width)
{
    neat_file.setf(ios::fixed);
    neat_file.setf(ios::showpoint);
    neat_file.setf(ios::showpos);
    neat_file.precision(number_after_decimalpoint);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(number_after_decimalpoint);

    double next;
    while(messy_file >> next)
    {
        cout << setw(field_width) << next << endl;
        neat_file << setw(field_width) << next << endl;
    }
}


