//Sorts a list of numbers entered at the keyboard.
#include <iostream>
#include <cstdlib>
#include <cstddef>

typedef int* IntArrayPtr;

void fill_array(int a[], int size);
//Precondition: size is the size of the array a.
//Postcondition: a[0] through a[size - 1] have been
//filled with values read from the keyboard.

void sort(int a[], int size);
//Precondition: size is the size of the array a.
//The array elements a[0] through a[size - 1] have values.
//Postcondition: The values of a[0] through a[size - 1] have been rearranged
//so that a[0] <= a[1] <= ... <= a[size - 1].

void swap_values(int& v1, int& v2);
//Interchanges the values of v1 and v2.

int index_of_smallest(const int a[], int start_index, int size);
//Precondition: 0 <= start_index < size. Referenced array elements have values.
//Returns the index i such that a[i] is the smallest of the values
//a[start_index], a[start_index + 1], ... , a[number_used -1].

int main()
{
    using namespace std;
    cout << "This program sorts numbers from lowest to highest.\n";

    int array_size;
    cout << "How many numbers will be sorted? ";
    cin >> array_size;

    IntArrayPtr a;
    a = new int[array_size];

    fill_array(a, array_size);
    sort(a, array_size);

    cout << "In sorted order the numbers are:\n";
    for (int index = 0; index < array_size; index++)
        cout << a[index] << " ";
    cout << endl;

    delete [] a;

    return 0;
}

//Uses the library iostream
void fill_array(int a[], int size)
{
    using namespace std;
    cout << "Enter " << size << " integers.\n";
    for (int index = 0; index < size; index++)
        cin >> a[index];
}

void sort(int a[], int size)
{
    int index_of_next_smallest;
    for (int index = 0; index < size - 1; index++)
    {
        //Place the correct value in a[index]:
        index_of_next_smallest = index_of_smallest(a, index, size);
        swap_values(a[index], a[index_of_next_smallest]);
    }
}

void swap_values(int& v1, int& v2)
{
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

int index_of_smallest(const int a[], int start_index, int size)
{
    int min = a[start_index], index_of_min = start_index;
    for (int index = start_index + 1; index < size; index++)
        if (a[index] < min)
        {
            min = a[index];
            index_of_min = index;
        }

    return index_of_min;
}
