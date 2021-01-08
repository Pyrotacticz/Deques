// ---------------------------- deque_test.cpp --------------------------------

// James Truong CSS501A

// Created: 11/25/2020

// Last Modified: 11/25/2020

// ----------------------------------------------------------------------------

// A driver that tests deque object methods such as adding and removing to the
// front and back of the deque in addition to the other queue-like methods like
// checking if the deque is empty or the size of the deque.
//
// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

// ----------------------------------------------------------------------------


#include <iostream>
#include "deque.h"
#include "deque.cpp"


using namespace std;

int main( ) {
  Deque<int> deque1;
  int item;

  for ( int j = 0; j < 5; j++ )
    deque1.addBack( j );
  for ( int j = 5; j < 10; j++ )
    deque1.addFront( j );

  Deque<int> deque2 = deque1;
  deque2.addBack( 10 );

  cout << "deque1: " << endl;
  while ( !deque1.isEmpty( ) )
    cout << deque1.removeFront( ) << endl;

  cout << "deque2: " << endl;
  while ( !deque2.isEmpty( ) )
    cout << deque2.removeBack( ) << endl;
}

// steps to completing this program
// 1. implement addFront, addBack, removeFront, removeBack
// 2. compile deque_test.cpp
// 3. implement LongInt using Deque class in longint.cpp
// 4. test input.txt and check output.txt
// 5. create own testing driver to test
// 6. print out testing output as MyTesting.txt