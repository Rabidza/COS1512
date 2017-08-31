#include <iostream>
using namespace std;

int main()
{
    double salary = 4500.00;
    double increase = 475.00;

    double *fPtr1, *fPtr2;
    fPtr2 = &salary;
    fPtr1 = &increase;
    cout << fPtr2 << endl;
    cout << *fPtr1 << endl;
    fPtr2 = new double;
    if (salary > 4200.00) *fPtr2 = *fPtr2 + *fPtr1;
    fPtr1 = fPtr2;
    delete fPtr2;
    cout << "CHECK HERE: " << *fPtr2 << endl;
    cout << *fPtr2 << endl; //475.00
    typedef double* DoublePtr;
    DoublePtr pd;
    pd = new double [20];
    delete [] pd;

    return 0;
}
