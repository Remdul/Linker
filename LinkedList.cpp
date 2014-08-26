#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include "LinkedList.h"

#define mark() {std::cout << "Location: " << __LINE__ << std::endl;}

using namespace std;


linkedList::Node::Node(int init_value) { 	// Don't understand this one bit yet.
//Node is an inner class of LinkedList, otherwise this is a regular constructor.
	value = init_value;						// Don't understand this one bit yet.
	//value is a member of Node. This sets the value of this instance of Node to its initial value
}											// Don't understand this one bit yet.

void linkedList::add_first_value(int value ) // For inserting into list
		{
	//Node *temp = new Node; 	// Create New Node //This should fail. 
	Node *temp = new Node(value);
	//Node has no default constructor. That is by design. It prevents the constructino of a 
	//Node without an initial value
	//temp->value = value;	// Populate Value
	//temp->next = NULL;		// Since this is initial node, no Next
	//temp->prev = NULL;		// Since this is initial node, no Previous
	//All this initialization needs should be done in the constructor of Node instead of here
	
	head = temp;			// Head of linkedList will be new node
	tail = temp;			// Tail of linkedList will be new node
}
void linkedList::addHead(int value) {
	if (isEmpty()) {		// Is this the first node?
		//insert isn't for inserting the first node, it is for inserting to an arbitrary position
		//if you want a function for the first element, call it something like initial_element
		//insert(value);		// If Yes, use insert to create it.
		add_initial_value(value);
	}						// else...
	//Node *temp 	= new Node;	// Create new node
	//Use constructor that sets initial value
	
	//temp->value = value;	// Assign value
	temp->next 	= head;		// Next node is the first node.
	//temp->prev	= NULL;		// Previous node doesn't exist.
	//This should be done in the constructor
	head->prev	= temp;		// First node's last is now new node.
	head 		= temp;		// Assign new node as the first node in list.
}

void linkedList::addTail(int value) {
	if (isEmpty()) {		// Is this the first node?
		add_initial_value(value);		// If Yes, use insert to create it.
	}						// else...
	Node *temp 	= new Node;	// Create new node
	temp->value = value;	// Assign value
	temp->next 	= NULL;		// Next node doesn't exist
	temp->prev	= tail;		// Previous node is now last node.
	tail->next 	= temp;		// Last node now points to new node
	tail 		= temp;		// Assign new node as the last node in list.
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
    cout << "This node doesn't exist..." << endl;
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
char menu() {
	char choice;
	cout << "Menu" << endl;
	cout << "1) Print List." << endl;
	cout << "2) Add an Item to End of List." << endl;
	cout << "3) Add an Item to Beginning of List." << endl;
	cout << "4) Get a Value from a place in the List." << endl;
	cout << "5) Exit Program." << endl;

	cin >> choice;
	return choice;
}

int main() {
	char choice;
	int number;

	do {
		choice = menu();
		switch (choice) {
		case '1':
			print();
			break;
		case '2':
			cout << "Insert Value to add to list: ";
			cin >> number;
			addTail(number);
			break;
		case '3':
			cout << "Insert Value to add to list: ";
			cin >> number;
			addHead(number);
			break;
		case '4':
			cout << "Insert Node to print Value: ";
			cin >> number;
			get(number);
			break;
		default:
			cout << "Invalid Option!" << endl;
			break;
		}

	} while (choice != '5');

	return 0;
}

