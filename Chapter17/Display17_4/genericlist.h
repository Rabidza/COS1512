//This is the header file genericlist.h. This is the interface for the
//class GenericList. Object of type GenericList can be a list of all items
//of any type for which the operators << and = are defined.
//All the items on any one list must be of the same type. A list that
//can hold up to max items all of type Type_Name is declared as follows:
//GenericList<Type_Name>the_object(max);
#ifndef GENERICLIST_H
#define GENERICLIST_H
#include <iostream>
using namespace std;

namespace listsavitch
{
    template<class ItemType>
    class GenericList
    {
    public:
        GenericList(int max);
        //Initializes the object to an empty list that can hold up to
        //max items of type ItemType.
        ~GenericList();
        //Returns all the dynamic memory used by the object to the freestore.

        int length() const;
        //Returns the number of items on the list.

        void add(ItemType new_item);
        //Precondition: The list is not full.
        //Postcondition: The new_item has been added to the list.

        bool full() const;
        //Returns true if the list is full.

        void erase();
        //Removes all items from the list so that the list is empty.

        friend ostream& operator <<(ostream& outs, const GenericList<ItemType>& the_list)
        {
            for (int i = 0; i < the_list.current_length; i++)
                outs << the_list.item[i] << endl;
            return outs;
        }
        //Overloads the << operator so it can be used to output the
        //contents of the list. The items are output one per line.
        //Precondition: If outs is a file output stream, then outs has
        //already been connected to a file.
        //
        //Note the implementation of the overloaded << in the header
        //file! This is commonly done with overloaded friend templates.
        //Since << is a friend it is NOT a memeber of the class but
        //rather in the namesoace, this is the simplest implementation
        //and may make more sense that putting it in genericlist.cpp.
    private:
        ItemType *item; //pointer to the dynamic arry that holds the list.
        int max_length; //max number of items allowed on the list.
        int current_length; //number of items currently on the list.
    };
}//listsavitch

#endif // GENERICLIST_H
