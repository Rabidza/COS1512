//Appends data to the end of the file data.txt
#include <fstream>
#include <iostream>
#include <cstdlib> // Textbook also omits this directive

int main()
{
    using namespace std;

    cout << "Opening data.txt for appending.\n";
    ofstream fout;
    fout.open("data.txt", ios::app);
    if (fout.fail())
    {
        cout << "Input file opening failed.\n"; // Typed as per text book, but this should be Output file
        exit(1);
    }

    fout << "5 6 Pick up sticks.\n"
         << "7 8 ain't C++ great!\n";

    fout.close();
    cout << "End of appending to file.\n";

    return 0;
}
