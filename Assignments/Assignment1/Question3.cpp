//Compute the median of a data file
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int countElements(ifstream& inStream);
//Counts the number of elements in a file

int getMedian(ifstream& inStream, int elementLength);
//Returns the median of a data file

int main()
{
    ifstream fin;
    int total, median;

    fin.open("file2.dat");
    if (fin.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    total = countElements(fin);
    fin.close();

    fin.open("file2.dat");
    getMedian(fin, total);

    fin.close();

    return 0;
}

int countElements(ifstream& inStream)
{
    int next;
    int counter = 0;

    while (inStream >> next)
        counter++;

    return counter;
}

int getMedian(ifstream& inStream, int elementLength)
{
    int next, nextFirst, nextSecond;
    int counter = 0;
    int nextCounter = 0;
    double answer;

    if (elementLength % 2 == 0)
    {
        while(counter < (elementLength / 2) && inStream >> nextFirst)
        {
            counter++;
        }
        inStream >> nextSecond;
        answer = static_cast<double>(nextFirst + nextSecond) / 2;
    }
    else
    {
        while(counter <= (elementLength / 2) && inStream >> next)
        {
            counter++;
            answer = next;
        }
    }

    cout << "The median is: " << answer << endl;
}
