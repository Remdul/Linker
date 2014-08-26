#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>

class linkedList {
public:
	linkedList();
	void insert (int value);
	void addHead(int value);
	void addTail(int value);
	void insertBefore(int value, int index);
	bool isEmpty() const;
	int size() const;
	int get(int index) const;
	void set(int index);
	void remove(int index);
	void swap(int index1, int index2);
	void print();

private:
	struct Node;
	Node *head;
	Node *tail;

};
class linkedList::Node {
	Node(int init_value);
	int value;
	Node *next;
	Node *prev;
};


#endif
