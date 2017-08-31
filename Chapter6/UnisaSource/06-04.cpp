//DISPLAY 6.4 Inputting a File Name
//Reads three numbers from the file specified by the user, sums the numbers,
//and writes the sum to another file specified by the user. 
#include <fstream>
#include <iostream>
#include <cstdlib>

int main( )
{
    using namespace std;
    char in_file_name[16], out_file_name[16];
    ifstream in_stream;
    ofstream out_stream;

    cout << "I will sum three numbers taken from an input\n"
         << "file and write the sum to an output file.\n";
    cout << "Enter the input file name (maximum of 15 characters):\n";
    cin >> in_file_name;
    cout << "Enter the output file name (maximum of 15 characters):\n";
    cin >> out_file_name;
    cout << "I will read numbers from the file "
         << in_file_name << " and\n"
         << "place the sum in the file "
         << out_file_name << endl;

    in_stream.open(in_file_name);
    if (in_stream.fail( ))
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    out_stream.open(out_file_name);
    if (out_stream.fail( ))
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    int first, second, third;
    in_stream >> first >> second >> third;
    out_stream << "The sum of the first 3\n"
               << "numbers in " << in_file_name << endl
               << "is " << (first + second + third)
               << endl;
    in_stream.close( );
    out_stream.close( );

    cout << "End of Program.\n";
    return 0;
}

