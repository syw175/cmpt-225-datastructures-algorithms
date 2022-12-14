/*
 * List.cpp
 *
 * Class Description: List data collection ADT.
 *                    Based on the Hashing strategy and the open addressing
 *                    collision resolution strategy called linear probing hashing.
 * Class Invariant: Data collection with the following characteristics:
 *                  - Each element is unique (no duplicates).
 *
 * Author: AL
 * Completed by: Steven Wong
 * Date: Last modified: Dec 2022
 */

#include <iostream>
#include <cstring>
#include "List.h"
#include "EmptyDataCollectionException.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "UnableToInsertException.h"

// Constructor
List::List(unsigned int (*hFcn)(string))
{
    this->hashFcn = hFcn;
}

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{    
    delete [] hashTable;


    // // Iterate through the hashTable and delete each element
    // for (int i = 0; i < CAPACITY; i++)
    // {
    //     if (hashTable[i] != nullptr)
    //         delete hashTable[i];
    // }
    // delete[] hashTable;
}

// Description: Returns the total element count currently stored in List.
// Postcondition: List remains unchanged.
unsigned int List::getElementCount() const
{
    return elementCount;
}

// Description: Insert an element.
// NOTE: You do not have to expand the hashTable when it is full.
// Precondition: newElement must not already be in in the List.
// Postcondition: newElement inserted and elementCount has been incremented.
// Exception: Throws UnableToInsertException if we cannot insert newElement in the List.
//            For example, if the operator "new" fails, or hashTable is full (temporary solution).
// Exception: Throws ElementAlreadyExistsException if newElement is already in the List.
void List::insert(Member &newElement)
{
    // Allocate memory for our hashTable if elementCount is 0
    if (getElementCount() == 0)
    {
        hashTable = new Member *[CAPACITY];
        if (hashTable == nullptr)
            throw UnableToInsertException("Insert() failed to insert newElement in the List: Memory Allocation Failed.");
        // Initialize all elements in hashTable to nullptr
        for (int i = 0; i < CAPACITY; i++)
            hashTable[i] = nullptr;
    }

    // Check if the hashTable is full
    if (getElementCount() == CAPACITY)
        throw UnableToInsertException("Insert() failed to insert newElement in the List: Capacity Reached.");
    // Otherwise insert the element into our List unless it is already in List
    else
    {
        // Get the index of the element to be inserted
        unsigned int index = hashFcn(newElement.getPhone());

        while (hashTable[index] != nullptr)
        {
            // If the element is already in the List, throw an exception
            if (*hashTable[index] == newElement)
                throw ElementAlreadyExistsException("Insert() failed to insert newElement in the List: Element Already Exists.");
            // Otherwise, increment the index and check the next element
            else
                index = (index + 1) % CAPACITY;
        }
        // Insert the element into the List
        hashTable[index] = &newElement;
        elementCount++;
    }
}

// Description: Returns a pointer to the target element if found.
// Postcondition: List remains unchanged.
// Exception: Throws EmptyDataCollectionException if the List is empty.
// Exception: Throws ElementDoesNotExistException if newElement is not found in the List.
Member* List::search(Member &target) const
{
    Member *result = nullptr;
    unsigned int index = hashFcn(target.getPhone());
    // Check if List is empty
    if (getElementCount() == 0)
        throw EmptyDataCollectionException("Search() called on an empty List.");

    // Search for the target element using linear probing
    while (hashTable[index] != nullptr)
    {
        // If the element is found, return a pointer to it
        if (*hashTable[index] == target)
        {
            result = hashTable[index];
            break;
        }
        // Otherwise, increment the index and check the next element
        else
            index = (index + 1) % CAPACITY;

        // If we have reached the end of the List and circled back to our starting index, throw an exception
        if (index == hashFcn(target.getPhone()))
            throw ElementDoesNotExistException("Search() called on an element that does not exist in the List.");
    }
    // If the element is not found, throw an exception
    if (result == nullptr)
        throw ElementDoesNotExistException("Search() called on an element that does not exist in the List.");
    return result;    
}

// Description: Prints all elements stored in the List (unsorted).
// Postcondition: List remains unchanged.
void List::printList() const
{
    // For each index, if the element is not nullptr, print the element
    cout << "{" << endl;
    for (unsigned int i = 0; i < CAPACITY; i++)
    {
        if (hashTable[i] != nullptr)
            cout << i << ": " << *hashTable[i];
    }
    cout << "}" << endl;
}