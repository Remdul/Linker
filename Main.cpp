#include <iostream>
#include <string>
#include "LinkedList.h"
#define mark() {std::cout << "Location: " << __LINE__ << std::endl;}

using namespace std;

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
	linkedList list;

	do {
		choice = menu();
		switch (choice) {
		case '1':
			list.print();
			break;
		case '2':
			cout << "Insert Value to add to list: ";
			cin >> number;
			list.addTail(number);
			break;
		case '3':
			cout << "Insert Value to add to list: ";
			cin >> number;
			list.addHead(number);
			break;
		case '4':
			cout << "Insert Node to print Value: ";
			cin >> number;
			list.get(number);
			break;
		default:
			cout << "Invalid Option!" << endl;
			break;
		}

	} while (choice != '5');
	return 0;
}
