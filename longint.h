// ------------------------------- longint.h ----------------------------------

// James Truong CSS501A

// Created: 11/25/2020

// Last Modified: 12/04/2020

// ----------------------------------------------------------------------------

// The longint class that represents a very long integer. The longint class
// allows addition, subtraction, longint comparison, and copying ohter longint
// objects.
//
// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.

// ----------------------------------------------------------------------------
#ifndef LONGINT_H
#define LONGINT_H
#include <iostream>
#include "deque.h"
#include "deque.cpp"

using namespace std;

class LongInt {

	/** Takes in a string and reads each numeric character as a valid input for
	* the LongInt. If '-' is the first character of the string, will make the
	* resulting LongInt negative. Will clear out all leading 0's in the
	* LongInt.
	* precondition: none.
	* postcondition: a LongInt containing the respective numbers of the string
	* except for leading "0" and is negative if there exists a '-' in front of
	* the string.
	*/
	friend istream &operator>>( istream &in, LongInt &rhs );

	/** Prints the LongInt number similar to how it prints integers. If
	* LongInt is negative, prints negative sign in front of the numbers. If
	* LongInt is empty or zero, prints "0".
	*/
	friend ostream &operator<<( ostream &out, const LongInt &rhs );
public:

	/** Creates a LongInt object using the passed in string.
	* precondition: the string has valid numbers. If '-' is in the front of the
	* string, the created LongInt will be negative.
	* postcondition: an LongInt object with the numbers of the string.
	*/
	LongInt( const string str );

	/** Copy constructor: creates a copy of the passed in LongInt.
	* precondition: another LongInt.
	* postcondition: a LongInt that is a copy of the rhs LongInt.
	*/
	LongInt( const LongInt &rhs );

	/** Default constructor: creates an empty LongInt.
	* precondition: none.
	* postcondition: an empty LongInt object.
	*/
	LongInt( );

	/** Destructor: clears the LongInt and destructs it.
	* precondition: none.
	* postcondition: a destructed LongInt.
	*/
	~LongInt( );

	/** Adds LongInt objects together.
	* precondition: another LongInt.
	* postcondition: Returns a LongInt with the sum of this and the rhs
	* LongInt.
	*/
	LongInt operator+( const LongInt &rhs ) const;

	/** Subtracts another LongInt from this LongInt.
	* precondition: another LongInt.
	* postcondition: Returns a LongInt with the result of
	* LongInt - rhs LongInt.
	*/
	LongInt operator-( const LongInt &rhs ) const;

	/** Assigns this LongInt as a copy of another LongInt.
	* precondition: another LongInt.
	* postcondition: this LongInt is a copy of the rhs LongInt.
	*/
	const LongInt &operator=( const LongInt &rhs );

	/** Checks if this LongInt is less than another LongInt.
	* precondition: another LongInt.
	* postcondition: returns true if this LongInt is less than rhs LongInt,
	* otherwise false.
	*/
	bool operator< ( const LongInt & rhs ) const;

	/** Checks if this LongInt is less than or equal to another LongInt.
	* precondition: another LongInt.
	* postcondition: returns true if this LongINt is less than or equal to
	* rhs LongInt.
	*/
	bool operator<=( const LongInt & rhs ) const;

	/** Checks if this LongInt is greater than another LongInt.
	* precondition: another LongInt.
	* postcondition: returns true if this LongINt is greater than rhs LongInt.
	*/
	bool operator> ( const LongInt & rhs ) const;

	/** Checks if this LongInt is greater than or equal to another LongInt.
	* precondition: another LongInt.
	* postcondition: returns true if this LongINt is greater than or equal to
	* rhs LongInt.
	*/
	bool operator>=( const LongInt & rhs ) const;

	/** Checks if this LongInt is equal to another LongInt.
	* precondition: another LongInt.
	* postcondition: returns true if this LongINt is equal to rhs LongInt.
	*/
	bool operator==( const LongInt & rhs ) const;

	/** Checks if this LongInt is not equal to another LongInt.
	* precondition: another LongInt.
	* postcondition: returns true if this LongINt is not equal to rhs LongInt.
	*/
	bool operator!=( const LongInt & rhs ) const;

	LongInt triple() const;


private:
	Deque<char> digits;
	bool negative;

	/** Removes all leading zeroes in the LongInt.
	* precondition: None.
	* postcondition: returns this LongInt with no leading zeroes.
	*/
	void remove0s( );
};

#endif
