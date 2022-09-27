/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Each element is in descending order of cell phone number.
 *
 * Author: Steven Wong
 * 
 * Last modified: Sept. 2022
 */

#include <iostream>
#include "List.h"
#include "Member.h"

using namespace std;

// REMOVE THIS COMMENT LATER
// List starts as NULL with element count = 0 
// If the list elementCount becomes 0, clear() is callled and array = NULL 
// For any additions, if elementCount is 0, array must be allocated on HEAP with CAPACITY

// DONE.. REMOVE THIS COMMENT LATER
// Default constructor
List::List() {}

// DONE.. REMOVE THIS COMMENT LATER
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{
    this->clear();
}

// DONE.. REMOVE THIS COMMENT LATER
// Description: Returns the total number of elements currently stored in List.
unsigned int List::getElementCount() const
{
    return elementCount;
}

// INCOMPLETE: REMOVE COMMENT LATER
/* Description: Insert an element.
 * Precondition: newElement must not already be in data collection.  
 * Postcondition: newElement inserted in its proper place in List
 *                and elementCount has been incremented.   
 */
bool List::insert(Member& newElement)
{
    bool result = true; 

    elements[getElementCount()] = newElement;
    elementCount++;
    // // Check if newElement is already in the data collection
    // if (search(newElement) == NULL) result = false;

    // // Check if there is still capacity in the array
    // if (CAPACITY <= getElementCount()) result = false; 

    // // Iterate through the array until current !< next (We found the right place for it)
    // for (unsigned int i = 0, k = getElementCount(); i < k; i++)
    // {
    //     // If this is true... we have found the place of newElement in the List
    //     if (elements[i] < newElement)
    //     {

    //     }
    // }
    
    return result;
}

// NEEDS CHECKING... REMOVE COMMENT LATER
/* Description: Remove an element. 
 * Postcondition: toBeRemoved is removed (leaving no gap in the data structure of List)
 *                and elementCount has been decremented.
 */
bool List::remove(Member& toBeRemoved)
{
    bool status = true;

    // Check if toBeRemoved exists in the data collection
    if (search(toBeRemoved) == NULL) status = false;

    if (status)
    {
        // Remove Element by shifting all elements after toBeRemoved
        for (unsigned int i = 0, k = getElementCount(); i < k; i++)
        {
            if (elements[i] == toBeRemoved)
            {
                for (unsigned int j = i; j < getElementCount(); j++)
                {
                    // position toward the beginning of the array
                    // (no shift if position == elementCount)
                    elements[j] = elements[j+1];
                }
            }
        }
        // Decrease count of elements
        elementCount--;
    }

    // If the list is empty, clear it...
    if (getElementCount() == 0) clear();

    // Return the status of remove()
    return status;
} 


// DONE.. REMOVE THIS COMMENT LATER
// Description: Removes all elements from the List.
// Postconditions: List contains no elements and the element count is 0.
//                 List is returned to the default state in the constructor.
void List::clear()
{
   delete [] elements;
   elements = NULL;
   elementCount = 0;
   return;
}

// ASK ABOUT THIS LATER.. 
// Description: Remove all elements.
// Postcondition: List is back to the state it was right after being constructed.
void List::removeAll()
{
    this->clear();
}

// DONE.. REMOVE THIS COMMENT LATER
// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Member* List::search(Member& target)
{
    // Initialize a pointer to a Member object
    Member *person = NULL;

    // Iterate through the array until we find the target
    for (unsigned int i = 0, j = getElementCount(); i < j; i++)
    {
        // If we find the target, set person to the address of the target
        if (elements[i] == target) person = &elements[i];
    }
    // Return the address of the target or NULL if not found
    return person;
}

// DONE.. REMOVE THIS COMMENT LATER
// Description: Prints all elements stored in List by descending order of search key.
// Time Efficiency: O(n)
void List::printList()
{
    for (unsigned int i = 0, j = getElementCount(); i < j; i++)
    {
        // Print the ith Member with the form: Louis Pace, 604-853-1423, louis@nowhere.com, 1234 5678 9098 7654 
        cout << elements[i] << endl;
    }
}
