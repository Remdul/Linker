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
};

bool isEmpty(Node *head);
char menu();
void insert(Node * &head, Node * &last, int value);
void prepend(Node * &head, Node * &last, int value);
void append(Node * &head, Node * &last, int value);
void remove(Node * &head, Node * &last);
void print(Node *current);

int main() {
	Node *head = NULL;
	Node *last = NULL;
	char choice;
	int number;

	do{
		choice = menu();
		switch(choice)
		{
		case '1':
			print(head);
			break;
		case '2':
			cout << "Please enter a number: ";
			cin >> number;
			append(head, last, number);
			break;
		case '3':
			cout << "Please enter a number: ";
			cin >> number;
			prepend(head, last, number);
			break;
		case '4':
			remove(head,last);
			break;
		default:
			cout << "Invalid Option!" << endl;

		}

	}while(choice != '5');

	return 0;
}


bool isEmpty(Node *head)
{
	if(head == NULL){
		return true;
	}
	else{
		return false;
	}
}

char menu(){
	char choice;
	cout << "Menu" << endl;
	cout << "1) Print List." << endl;
	cout << "2) Add an Item to List." << endl;
	cout << "3) Prepend an Item." << endl;
	cout << "4) Remove an Item." << endl;
	cout << "5) Exit Program." << endl;

	cin >> choice;
	return choice;
}

void insert(Node * &head, Node * &last, int value){
	Node *temp = new Node;
	temp->_value = value;
	temp->_nodeNext = NULL;
	temp->_nodePrev = NULL;
	head = temp;
	last = temp;
}

void append(Node * &head, Node * &last, int value){
	if(isEmpty(head))
	{
		insert(head, last, value);
	}
	else
	{
		Node *temp = new Node;
		temp->_value = value;
		temp->_nodeNext = NULL;
		temp->_nodePrev = last;
		last->_nodeNext = temp;
		last = temp;
	}
}

void prepend(Node * &head, Node * &last, int value){
	if(isEmpty(head))
	{
		insert(head, last, value);
	}
	else
	{
		Node *temp = new Node;
		temp->_value = value;
		temp->_nodeNext = head;
		temp->_nodePrev = NULL;
		head->_nodePrev = temp;
		head = temp;
	}
}

void remove(Node * &head, Node * &last){
	int line;
	if(isEmpty(head))
	{
		cout << "This list is empty. No need to delete anything!" << endl;
	}
	else if (head == last)
	{
		delete head;
		head == NULL;
		last == NULL;
	}
	else
	{
		Node * temp = head;
		head = head->_nodeNext;
		delete temp;
	}
}

void print(Node *current){
	int i;
	if (isEmpty(current))
	{
		cout << "The list is empty! :(" << endl;
	}
	else
	{
		cout << "This list contains: " << endl;

		while (current != NULL)
		{
			cout << current->_value << endl;
			current = current->_nodeNext;
		}
	}
}
