/*
 * Stack.cpp
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Steven Wong
 * Date: October 2022
 */

#include <iostream>
#include <exception>
#include "Stack.h"

// Default Constructor
Stack::Stack() {}

// Destructor
Stack::~Stack()
{   
    // Iterate through the linked list and deallocate nodes from the heap
    StackNode *current = head;
    while (current != nullptr)
    {
        StackNode *next = current->next;
        // Delete the current node and move to the next node
        delete current;
        current = next;
    }
}

// Returns true if the Stack is empty and false otherwise
bool Stack::isEmpty() const
{
    return size() == 0;
}

// Pre-Condition: The stack must not be empty
// Retrieve and return the top most element of the stack
int Stack::peek() const
{
    // Ensure that the pre-condition is met
    if (isEmpty())
        throw std::runtime_error("Stack is empty. Cannot peek.");
 
    // Iterate to the last node in the SHSL linked list (the top of the stack)
    StackNode *current = head;
    while (current->next != nullptr)
        current = current->next;

    // Return the data of the last node
    return current->data;
}

// Insert an element onto the top of the stack and return true if successful, false otherwise
bool Stack::push(int newElement)
{
    bool pushed = true;
    // Create a new StackNode and set its data to the newElement
    StackNode *newNode = new StackNode;
    newNode->data = newElement;
    newNode->next = nullptr;

    // If memory allocation failed, set pushed to false
    if (newNode == nullptr)
        pushed = false;
    // If the stack is empty, set the head to newElement and increment elementCount
    else if (isEmpty())
    {
        head = newNode;
        elementCount++;
    }
    // Iterate to the last node in the SHSL (top of stack)
    else
    {
        StackNode *current = head;
        while (current->next != nullptr)
            current = current->next;

        // Set the nex pointer of the last node to NewNode
        current->next = newNode;
        elementCount++;
    }
    return pushed;
}

// Remove the top most element of the stack, return true if successful, false otherwise
bool Stack::pop()
{
    bool popped = true;
    // If the stack is empty, set the status of popped to false
    if (isEmpty())
        popped = false;
    // If the stack only has one element, delete the head and set it to nullptr
    else if (size() == 1)
    {
        delete head;
        head = nullptr;
        elementCount--;
    }
    // If the stack has more than one element, iterate to the second last node in the SHSL linked list
    else
    {
        StackNode *current = head;
        while (current->next->next != nullptr)
            current = current->next;

        // Delete the last node and set the next pointer of the second last node to nullptr
        delete current->next;
        current->next = nullptr;
        elementCount--;
    }
    // Return the status of popped
    return popped;
}

// Returns the number of elements in the stack
unsigned int Stack::size() const
{
    return elementCount;
}
