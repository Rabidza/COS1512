#include <iostream>
using namespace std;

int main()
{
    int count;
    cout << "Please enter the count: ";
    cin >> count;

    int* p1;
    p1 = new int [count];
    for (int index = 0; index < count; index++)
    {
        p1[index] = index;
    }

    for (int index = 0; index < count; index++)
        cout << p1[index] << endl;

    delete [] p1;
}
