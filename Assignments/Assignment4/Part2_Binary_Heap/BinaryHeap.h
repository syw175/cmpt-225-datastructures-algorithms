/* 
 * BinaryHeap.h
 *
 * Description: Minimum Binary Heap ADT class.
 *
 * Class Invariant:  Always a minimum Binary Heap. The parent's value is always less than the child's value.
 * 
 * Author: Steven Wong
 * Last Modification: November 2022
 *
 */

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <iostream>
#include <cmath>
#include "EmptyDataCollectionException.h"

template <class ElementType>
class BinaryHeap
{
    private:
        static const unsigned int INITIAL_CAPACITY = 10;
        static const unsigned int ROOT = 0;

        ElementType *heap; // Array of elements in the heap
        unsigned int elementCount; // Number of elements in the heap
        unsigned int capacity; // Current capacity of the heap array

        // Description: Recursively put the array back into a Minimum Binary Heap.
        void reHeapDown(unsigned int index);

        // Description: Recursively put the array back into a Minimum Binary Heap.
        void reHeapUp(unsigned int index);

        // Description: Swap the values of two elements in the array.
        void swap(unsigned int index1, unsigned int index2);

        // Description: Expanding the size of an array that is full
        void expand(int newSize);

    public:
        // Description: Default Constructor
        BinaryHeap();

        // Description: Copy Constructor
        BinaryHeap(const BinaryHeap<ElementType> &b);

        // Description: Destructor
        ~BinaryHeap();

        // Description: Returns the number of elements in the BinaryHeap.
        // Postcondition: BinaryHeap is unchanged.
        // Time Efficiency: O(1)
        unsigned int getElementCount() const;

        // Description: Insert newElement in the BinaryHeap, return true if successful.
        // Time Efficiency: O(log2 n)
        bool insert(ElementType &newElement);

        // Description: Remove the element with the lowest value in the BinaryHeap.
        // Precondition: BinaryHeap is not empty.
        // Exception: Throws EmptyDataCollectionException if BinaryHeap is empty.
        // Time Efficiency: O(log2 n)
        void remove();

        // Description: Retrieve the element with the lowest value in the BinaryHeap.
        // Precondition: BinaryHeap is not empty.
        // Postcondition: The BinaryHeap is unchanged.
        // Exceptions: Throws EmptyDataCollectionException if BinaryHeap is empty.
        // Time Efficiency: O(1)
        ElementType &retrieve() const;

        // For testing purposes only.
        // Description: Prints a string representation of the BinaryHeap.
        // Postcondition: The BinaryHeap is unchanged.
        // Time Efficiency: O(n)
        void print() const;
};
#include "BinaryHeap.cpp"
#endif
