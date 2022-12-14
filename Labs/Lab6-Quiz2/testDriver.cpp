/* 
 * testDriver.cpp
 *
 * Description: Test drive the Data Collection ADT class.
 *
 * Author: AL
 * Date: Oct. 2022
 */
 
#include <iostream>
#include "UnableToInsertException.h"
#include "EmptyDataCollectionException.h"
#include "DataCollection.h"

using namespace std;

int main () {
   DataCollection * aDC1 = new DataCollection( );
   DataCollection * aDC2 = new DataCollection( );
   DataCollection * aDC3 = new DataCollection( );
      
// Test case 1 - Empty DataCollection 1
   cout << "Test Case 1 - Just constructed a DataCollection 1:" << endl;
   cout << "Empty DataCollection 1: " << *aDC1 << endl;

// Test case 2 - Prepending a few elements: 1 2 3 4 5 6 to DataCollection 1
   cout << "Test Case 2 - Prepending a few elements: 1 2 3 4 5 6 to DataCollection 1:" << endl;
   cout << "              expecting: 6 5 4 3 2 1 in DataCollection 1:" << endl;


   for (unsigned int i = 1; i <= 6; i++) {
      try {
	    cout << "Prepending " << i << " to DataCollection 1" << endl;
            aDC1->prepend( i );
      }
      catch ( UnableToInsertException & anException ) {
	    cout << "prepend() unsuccessful because " << anException.what() << endl;
      }
   }
   cout << "Content of DataCollection 1: " << *aDC1 << endl;
   

// Test case 3 - Appending a few elements: 1 2 3 4 5 6 to DataCollection 2
   cout << "Test Case 3 - Appending a few elements: 1 2 3 4 5 6 to DataCollection 2:" << endl;
   cout << "              expecting: 1 2 3 4 5 6  in DataCollection 2:" << endl;


   for (unsigned int i = 1; i <= 6; i++) {
      try {
         cout << "Appending " << i << " to DataCollection 2" << endl;
         aDC2->append( i );
      }
      catch ( UnableToInsertException & anException ) {
         cout << "append() unsuccessful because " << anException.what() << endl;
      }
   }
   cout << "Content of DataCollection 2: " << *aDC2 << endl;


// Test case 4 - Prepending and Appending a few elements to DataCollection 3
   cout << "Test Case 3 - Prepending and Appending a few elements to DataCollection 3:" << endl;
   cout << "              expecting: 3 4 1 2 5 6  in DataCollection 3:" << endl;


   try {
      cout << "Appending 1 to DataCollection 3" << endl;
      aDC3->append( 1 );
   }
   catch ( UnableToInsertException & anException ) {
      cout << "append() unsuccessful because " << anException.what() << endl;
   }
   try {
      cout << "Appending 2 to DataCollection 3" << endl;
      aDC3->append( 2 );
   }
   catch ( UnableToInsertException & anException ) {
      cout << "append() unsuccessful because " << anException.what() << endl;
   }
   try {
      cout << "Prepending 4 to DataCollection 3" << endl;
      aDC3->prepend( 4 );
   }
   catch ( UnableToInsertException & anException ) {
      cout << "append() unsuccessful because " << anException.what() << endl;
   }
   try {
      cout << "Prepending 3 to DataCollection 3" << endl;
      aDC3->prepend( 3 );
   }
   catch ( UnableToInsertException & anException ) {
      cout << "append() unsuccessful because " << anException.what() << endl;
   }
   try {
      cout << "Appending 5 to DataCollection 3" << endl;
      aDC3->append( 5 );
   }
   catch ( UnableToInsertException & anException ) {
      cout << "append() unsuccessful because " << anException.what() << endl;
   }
   try {
      cout << "Appending 6 to DataCollection 3" << endl;
      aDC3->append( 6 );
   }
   catch ( UnableToInsertException & anException ) {
      cout << "append() unsuccessful because " << anException.what() << endl;
   }
   cout << "Content of DataCollection 3: " << *aDC3 << endl;

   cout << "The elements in DC1 are... " << endl;
   cout << *aDC1 << endl;
   cout << "The average floating point value is... " << endl;
   cout << aDC1->average() << endl;

   // Testing with empty data Collection avg
   DataCollection *aDC5 = new DataCollection();
   try
   {
      aDC5->average();
   }
   catch (EmptyDataCollectionException &e)
   {
      cout << "Exception caught!" << endl;
   }

   cout << "Now removing the middle element in DC1" << endl;
   cout << "The current elements are..." << endl;
   cout << *aDC1 << endl;

   aDC1->removeMiddle();
   cout << "The elements after the removal is..." << endl;
   cout << *aDC1 << endl;

   cout << "Remove another" << endl;
   aDC1->removeMiddle();
   cout << "The elements after the removal is..." << endl;
   cout << *aDC1 << endl;

   // Testing seg fault
   cout << "Remove another til one left" << endl;
   aDC1->removeMiddle();
   aDC1->removeMiddle();
   aDC1->removeMiddle();
   cout << *aDC1 << endl;
   aDC1->removeMiddle();
   cout << *aDC1 << endl;

   // Testing with empty data Collection remove
   try
   {
      aDC1->removeMiddle();
   }
   catch(EmptyDataCollectionException &e)
   {
      cout << "Exception caught!" << endl;
   }
   












   delete aDC1;
   aDC1 = nullptr;
    
   delete aDC2;
   aDC2 = nullptr;
    
   delete aDC3;
   aDC3 = nullptr;
    
   return 0;
}
