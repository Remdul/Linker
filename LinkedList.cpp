#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include "LinkedList.h"

#define mark() {std::cout << "Location: " << __LINE__ << std::endl;}

using namespace std;

class linkedList::Node {
public:
	Node(int init_value);
	int value;
	Node *next;
	Node *prev;
};


linkedList::Node::Node(int init_value) { 	// Node is an inner class of LinkedList, otherwise this is a regular constructor.
	value 	= init_value;						// value is a member of Node. This sets the value of this instance of Node to its initial value
	prev	= NULL;
	next	= NULL;
}

void linkedList::add_initial_value(int value ) // For inserting into list
		{
	Node *temp = new Node(value);
	head = temp;			// Head of linkedList will be new node
	tail = temp;			// Tail of linkedList will be new node
}

void linkedList::addHead(int value) {
	if (isEmpty()) {				// Is this the first node?
		add_initial_value(value);	// If so, Create Initial Node
			}						// Otherwise...
	Node *temp 	= new Node(value);	// Create New Node
	temp->next 	= head;				// Next node is the first node.
	head->prev	= temp;				// First nodes last is now new node.
	head 		= temp;				// Assign new node as the first node in list.
}

void linkedList::addTail(int value) {
	if (isEmpty()) {				// Is this the first node?
		add_initial_value(value);	// If so, Create Initial Node
			}						// Otherwise...
	Node *temp 	= new Node(value);	// Create New Node
	temp->prev	= tail;				// Previous node is now last node.
	tail->next 	= temp;				// Last node now points to new node
	tail 		= temp;				// Assign new node as the last node in list.
}

void linkedList::insertBefore(int value, int index) {
}


bool linkedList::isEmpty() const {
	if (head == NULL) {
		return true;
	} else {
		return false;
	}
}

int linkedList::size() const {
	Node* temp = head; 			// Find start of list.
	int count = 0;				// Initialize count.
	//Be more explicit
	while (NULL != temp) {				// While loop
		count++;
		temp = temp->next; 		// Move to the next node
	}
	return count;
}

int linkedList::get(int index) const {
    Node* temp = head;
    int count = 0;
    while (temp != NULL)
    {
       if (count == index)
          return(temp->value);
       count++;
       temp = temp->next;
    }
    cout << "This node does not exist..." << endl;
    return 0;
}
void linkedList::print() {
	Node* temp = head;
	int i;
	int count = 0;

	if (isEmpty()) {
		cout << "The list is empty!" << endl;
	} else {
		cout << "This list contains: " << endl;

		while (temp != NULL) {
			cout << "[" << count << "] "<< temp->value << endl;
			temp = temp->next;
			count++;
		}
	}
}

void linkedList::set(int index) {

}
void linkedList::remove(int index) {

}
void linkedList::swap(int index1, int index2) {

}

