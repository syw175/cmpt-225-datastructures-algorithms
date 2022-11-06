// Used to test the Queue class
// Some basic tests for << operator
// Author: SW
// Date Last modified: November 2022

#include <iostream>
#include <string>
#include "EmptyDataCollectionException.h"
#include "Queue.h"

using namespace std;

int main(void)
{
    // Declare some integers
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;

    // Declare reference variables
    int &aRef = a;
    int &bRef = b;
    int &cRef = c;
    int &dRef = d;
    int &eRef = e;

    // Declare a Queue of integers
    Queue<int> *q = new Queue<int>();
    
    cout << "Test 1: Print an empty queue" << endl;
    cout << "Expected: {}" << endl;
    cout << "Actual: " << *q << endl << endl;

    cout << "Test 2: Print a queue with one element" << endl;
    q->enqueue(aRef);
    cout << "Expected: {1}" << endl;
    cout << "Actual: " << *q << endl << endl;

    cout << "Test 3: Print a queue with two elements" << endl;
    q->enqueue(bRef);
    cout << "Expected: {1, 2}" << endl;
    cout << "Actual: " << *q << endl << endl;

    cout << "Test 4: Print a queue with five elements" << endl;
    q->enqueue(cRef);
    q->enqueue(dRef);
    q->enqueue(eRef);
    cout << "Expected: {1, 2, 3, 4, 5}" << endl;
    cout << "Actual: " << *q << endl << endl;

    cout << "*********************************" << endl << "*********************************" << endl << endl;
    cout << "Testing with strings" << endl;

    // Going with strings now
    string s1 = "one";
    string s2 = "two";
    string s3 = "three";
    string s4 = "four";
    string s5 = "five";

    // Declare a Queue of strings
    Queue<string> *q2 = new Queue<string>();

    cout << "Test 1: Print an empty queue of strings" << endl;
    cout << "Expected: {}" << endl;
    cout << "Actual: " << *q2 << endl << endl;

    cout << "Test 2: Print a queue with one element" << endl;
    q2->enqueue(s1);
    cout << "Expected: {one}" << endl;
    cout << "Actual: " << *q2 << endl << endl;

    cout << "Test 3: Print a queue with five elements" << endl;
    q2->enqueue(s2);
    q2->enqueue(s3);
    q2->enqueue(s4);
    q2->enqueue(s5);

    cout << "Expected: {one, two, three, four, five}" << endl;
    cout << "Actual: " << *q2 << endl << endl;

    cout << "Looks like it's working!" << endl;
    return 0;
}