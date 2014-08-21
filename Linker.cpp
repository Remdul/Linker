#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#define mark() {std::cout << "Location: " << __LINE__ << std::endl;}

using namespace std;
// Class holds linked list of ints
// Member function called AT <- Returns int at given index
// Function called Insert <- Inserts before given index
// Delete member function <- removes from linked list
// To Vector Function <- ret returns all information in list
// Clear <- DELETES everything out of the list
// Swap <-
// VALGRIND <--

bool quit = false;

struct Node {
	int _value;
	Node *_nodeNext;
	Node *_nodePrev;

public:
	Node(void);
	Node(int val);
};

Node::Node(int val) {
	_value = val;
	_nodeNext = NULL;
}

Node::Node(void) {
	_nodeNext = NULL;
}




class LinkedList {
public:
	LinkedList(void);
	~LinkedList(void);
	void print();
	void append(int value);
	void prepend(int value);
	void add(int value);
	bool isEmpty();
private:
	Node *_listStart;
	Node *_listEnd;

};

bool LinkedList::isEmpty() {
	if (_listStart == NULL) {
		return true;
	}
	return false;
}
// Initializing Linked List
LinkedList::LinkedList() {
	_listStart = _listEnd = NULL;
}

LinkedList::~LinkedList() {

}

void LinkedList::append(int value) {
	Node *node = new Node(value);
	if (isEmpty()) {
		mark();
		_listStart = node;
	} else {
		mark();
		_listEnd->_nodeNext = node;
	}
	_listEnd = node;
}

void LinkedList::prepend(int value) {
	Node *node = new Node(value);
	if (isEmpty()) {
		_listStart = node;
	} else {
		_listStart->_nodeNext = node;
	}
	_listEnd = node;
}

void LinkedList::print() {
	Node *p = _listStart;
if (isEmpty()) {
	cout << "There's nothing to print. The list is empty." << endl;
	return;
	}
	cout << "Linked List: " << endl;
	while (p != NULL) {
		cout << p->_value << endl;
		p = p->_nodeNext;
	}
	cout << endl;
}

void mainMenu(LinkedList &list) {
	int add;
	int arg2;
	cout << "1) Print List." 				<< endl;
	cout << "2) Append to List." 			<< endl;
	cout << "3) Prepend to List." 			<< endl;
	cout << "4) Delete from List." 			<< endl;
	cout << "5) Quit" 						<< endl;
	cout << "   ==================" 		<< endl;
	cout << "What would you like to do: " 	<< endl;
	cin >> add;

	if (add == 1) {
		list.print();
	} else if (add == 2) {
		cout << "Value to Append: ";
		cin >> arg2;
		list.append(arg2);
	} else if (add == 3) {
		cout << "Value to Prepend: ";
		cin >> arg2;
		list.prepend(arg2);
	} else if (add == 4) {
		cout << "Value to Delete: ";
		cin >> arg2;
		list.append(arg2);
	} else if (add == 5) {
		quit = true;
	}

}

int main() {
	LinkedList list;

	while (quit == false) {
		mainMenu(list);
	}
	return 0;
}
