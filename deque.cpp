// ---------------------------- deque.cpp -------------------------------------

// James Truong CSS501A

// Created: 11/25/2020

// Last Modified: 12/04/2020

// ----------------------------------------------------------------------------

// The implementation file of the deque class that represents a double-sided
// queue. The deque class allows adding and removing objects only to the
// front and back of the deque object.
//
// ----------------------------------------------------------------------------

// Notes on specifications, special algorithms, and assumptions.
// Assumes when using removeFront() or removeBack(), there is a node to
// remove.

// ----------------------------------------------------------------------------

#include "deque.h"

/** Default constructor: creates an empty Deque.
* precondition: none.
* postcondition: an empty Deque object.
*/
template <class Object>
Deque<Object>::Deque( ) {
    front = back = NULL;
}

/** Copy constructor: creates a copy of rhs Deque as a new Deque.
* precondition: none.
* postcondition: a copy of the rhs Deque object.
*/
template <class Object>
Deque<Object>::Deque( const Deque &rhs ) {
    front = back = NULL;
    *this = rhs;
}

/** Destructor: deconstructs the Deque object.
* precondition: a rhs Deque.
* postcondition: a destructed Deque object.
*/
template <class Object>
Deque<Object>::~Deque( ) {
    clear( );
}

/** Checks if the Deque is empty.
* precondition: none.
* postcondition: returns true if the Deque is empty, otherwise false.
*/
template <class Object>
bool Deque<Object>::isEmpty( ) const {
    return front == NULL;
}

/** Returns the number of items in the Deque.
* precondition: none.
* postcondition: returns the number of nodes in the Deque object.
*/
template <class Object>
int Deque<Object>::size( ) const {
    int i = 0;
    for ( DequeNode *ptr = front; ptr != NULL; ptr = ptr->next )
        ++i;

    return i;
}

/** Gets the node item in front of the Deque.
* precondition: Deque is not empty, otherwise throws "Deque is empty.".
* postcondition: returns the front node item in the Deque.
*/
template <class Object>
const Object &Deque<Object>::getFront( ) const {
    if ( isEmpty( ) )
        throw "empty queue";
    return front->item;
}

/** Gets the node item in back of the Deque.
* precondition: Deque is not empty, otherwise throws "Deque is empty.".
* postcondition: returns the back node item in the Deque.
*/
template <class Object>
const Object &Deque<Object>::getBack( ) const {
    if ( isEmpty( ) )
        throw "empty queue";
    return back->item;
}

/** Clears the Deque until it contains no nodes.
* precondition: none.
* postcondition: an empty Deque object.
*/
template <class Object>
void Deque<Object>::clear( ) {          // clean up all entries.
    while ( !isEmpty( ) )                 // dequeue till the queue gets empty.
        removeFront( );
}

/** Adds a new node to the front of the Deque.
* precondition: an obj to add to the Deque.
* postcondition: the Deque object with a new front node.
*/
template <class Object>
void Deque<Object>::addFront( const Object &obj ) {
    DequeNode *ptr = new DequeNode();
    ptr->item = obj;
    ptr->next = front;
    ptr->prev = NULL;
    if (front != NULL)
    {
        front->prev = ptr;
    }
    else
    {
        back = ptr;
    }
    front = ptr;
    ptr = NULL;
}

/** Adds a new node to the back of the Deque.
* precondition: an obj to add to the Deque.
* postcondition: the Deque object with a new back node.
*/
template <class Object>
void Deque<Object>::addBack( const Object &obj ) { 
    DequeNode* ptr = new DequeNode();
    ptr->item = obj;
    ptr->prev = back;
    ptr->next = NULL;
    if (back != NULL)
    {
        back->next = ptr;
    }
    else
    {
        front = ptr;
    }
    back = ptr;
    ptr = NULL;
}

/** Return the front node item and removes the front node of the Deque.
* precondition: there is a front node to remove, otherwise throws
* "Deque is empty." error.
* postcondition: returns the front node item. The Deque is without the
* front node.
*/
template <class Object>
Object Deque<Object>::removeFront( ) {  // remove the front node
    Object removedItem;
    DequeNode *remove = front;
    if (isEmpty()) {
        throw "Deque is Empty.";
    }
    removedItem = front->item;
    if (front == back)
    {
        back = NULL;
    }
    front = front->next;
    remove->next = NULL;
    delete remove;
    return removedItem;
}

/** Return the back node item and removes the back node of the Deque.
* precondition: there is a back node to remove, otherwise throws
* "Deque is empty." error.
* postcondition: returns the back node item. The Deque is without the
* back node.
*/
template <class Object>
Object Deque<Object>::removeBack( ) {   // remove the tail node
    Object removedItem;
    DequeNode* remove = back;
    if (isEmpty()) {
        throw "Deque is Empty.";
    }
    removedItem = back->item;
    if (front == back)
    {
        front = NULL;
    }
    back = back->prev;
    remove->prev = NULL;
    delete remove;
    return removedItem;
}

/** Assigns this Deque as a copy of the other Deque.
* precondition: a rhs Deque.
* postcondition: returns this Deque as a copy of rhs Deque.
*/
template <class Object>
const Deque<Object> &Deque<Object>::operator=( const Deque &rhs ) { // assign
    if ( this != &rhs ) { // avoid self assignment
        clear( );
        for ( DequeNode *rptr = rhs.front; rptr != NULL; rptr = rptr->next )
            addBack( rptr->item );
    }
    return *this;
}


