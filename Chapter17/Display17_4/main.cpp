//Program to demonstrate use of the class template GenericList.
#include <iostream>
#include "genericlist.h"
#include "genericlist.cpp"
using namespace std;
using namespace listsavitch;

int main()
{
    GenericList<int> first_list(2);
    first_list.add(1);
    first_list.add(2);
    cout << "first_list = \n"
         << first_list;
    GenericList<char> second_list(10);
    second_list.add('A');
    second_list.add('B');
    second_list.add('C');
    cout << "second_list = \n"
         << second_list;

    return 0;
}
