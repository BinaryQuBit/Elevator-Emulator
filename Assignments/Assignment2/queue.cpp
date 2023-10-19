/**
   Project: Implementation of a Queue in C++.
   Programmer: Karim Naqvi
   Course: enel452
*/

#include "queue.h"
#include <iostream>
#include <cstdlib>              // for exit

using namespace std;

Queue::Queue()
{
    head = 0;
    tail = 0;
    nelements = 0;
    verbose = false;
}

Queue::~Queue()
{
    for (QElement* qe = head; qe != 0;)
    {
	QElement* temp = qe;
	qe = qe->next;
	delete(temp);
    }
}

void Queue::remove(Data* d)
{
    if (size() > 0)
    {
        QElement* qe = head;
        head = head->next;
        nelements--;
        *d = qe->data;
	delete qe;
    }
    else
    {
        cerr << "Error: Queue is empty.\n";
        exit(1);
    }
}

void Queue::insert(Data d)
{
    if (verbose) std::cout << "insert(d)\n";
    QElement* el = new QElement(d);
    if (size() > 0)
    {
        tail->next = el;
    }
    else
    {
        head = el;
    }
    tail = el;
    nelements++;
}

// This is added by Amandip Padda
// Function Defination
void Queue::insert(Data d, unsigned position)
{
// Condition check for error:: if position is greater than size, output error code
// with termination code 3
    if (position > size()) {
        cerr << "insert: range error.\n";
        exit(3);
    }

// newElement has been created of type QElement = data(d), points to newElement
    QElement* newElement = new QElement(d);
// Checking infront of the list
    if (position == 0)
    {
// If found point the newElement to next and equate to head
        newElement->next = head;
// head is now new element
        head = newElement;
// checking if empty
        if (size() == 0)
        {
// tail is now and only one in te linkedlist as newElement
            tail = newElement;
        }
    }
// Lastly check any other position
    else 
    {
// previous is pointing to the head
        QElement* previous = head;
// iterate thorough the loop just before the position and insert ++i
        for (unsigned i = 1; i < position; ++i)
        {
// Keep moving the previous to next through iteration
            previous = previous->next;
        }
// Next pointer of newElement = previous pointing to next
        newElement->next = previous->next;
// updates to point to newElement
        previous->next = newElement;

// if it is suppose to be inserted to the tail
        if (position == size())
        {
// make it equal to tail
            tail = newElement;
        }
    }
// increment number by 1
    nelements++;
}

bool Queue::search(Data otherData) const
{
    QElement* insideEl = head;
    for (int i = 0; i < nelements; i++)
    {
        if (insideEl->data.equals(otherData))
            return true;
        insideEl = insideEl->next;
    }
    return false;
}

void Queue::print() const
{
    QElement* qe = head;
    if (size() > 0)
    {
        for (unsigned i = 0; i < size(); i++)
        {
            cout << i << ":(" << qe->data.x << "," << qe->data.y << ") ";
            qe = qe->next;
        }
    }
    cout << "\n";
}

unsigned Queue::size() const
{
    return nelements;
}