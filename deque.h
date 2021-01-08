// ------------------------------- deque.h ------------------------------------

// James Truong CSS501A

// Created: 11/25/2020

// Last Modified: 12/04/2020

// ----------------------------------------------------------------------------

// The deque class that represents a double-sided queue. The deque class allows
// adding and removing objects only to the front and back of deque object. 
//
// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.
// Assumes when using removeFront() or removeBack(), there is a node to
// remove.

// ----------------------------------------------------------------------------

#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>

using namespace std;

template <class Object>
class Deque {
public:

	/** Default constructor: creates an empty Deque.
	* precondition: none.
	* postcondition: an empty Deque object.
	*/
	Deque( );

	/** Copy constructor: creates a copy of rhs Deque as a new Deque.
	* precondition: none.
	* postcondition: a copy of the rhs Deque object.
	*/
	Deque( const Deque &rhs );

	/** Destructor: deconstructs the Deque object.
	* precondition: a rhs Deque.
	* postcondition: a destructed Deque object.
	*/
	~Deque( );

	/** Checks if the Deque is empty.
	* precondition: none.
	* postcondition: returns true if the Deque is empty, otherwise false.
	*/
	bool isEmpty( ) const;

	/** Returns the number of items in the Deque.
	* precondition: none.
	* postcondition: returns the number of nodes in the Deque object.
	*/
	int size() const;

	/** Gets the node item in front of the Deque.
	* precondition: Deque is not empty, otherwise throws "Deque is empty.".
	* postcondition: returns the front node item in the Deque.
	*/
	const Object &getFront( ) const;

	/** Gets the node item in back of the Deque.
	* precondition: Deque is not empty, otherwise throws "Deque is empty.".
	* postcondition: returns the back node item in the Deque.
	*/
	const Object &getBack( ) const;

	/** Clears the Deque until it contains no nodes.
	* precondition: none.
	* postcondition: an empty Deque object.
	*/
	void clear( );

	/** Adds a new node to the front of the Deque.
	* precondition: an obj to add to the Deque.
	* postcondition: the Deque object with a new front node.
	*/
	void addFront( const Object &obj );

	/** Adds a new node to the back of the Deque.
	* precondition: an obj to add to the Deque.
	* postcondition: the Deque object with a new back node.
	*/
	void addBack( const Object &obj );

	/** Return the front node item and removes the front node of the Deque.
	* precondition: there is a front node to remove, otherwise throws
	* "Deque is empty." error.
	* postcondition: returns the front node item. The Deque is without the
	* front node.
	*/
	Object removeFront( );

	/** Return the back node item and removes the back node of the Deque.
	* precondition: there is a back node to remove, otherwise throws
	* "Deque is empty." error.
	* postcondition: returns the back node item. The Deque is without the
	* back node.
	*/
	Object removeBack( );

	/** Assigns this Deque as a copy of the other Deque.
	* precondition: a rhs Deque.
	* postcondition: returns this Deque as a copy of rhs Deque.
	*/
	const Deque &operator=( const Deque &rhs );

private:
	struct DequeNode {                          // a deque node
		Object item;
		DequeNode *next;
		DequeNode *prev;
	};
	DequeNode *front;
	DequeNode *back;
};

#endif
