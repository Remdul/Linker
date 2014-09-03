#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>

class linkedList
{
public:
    linkedList();
    void add_first_value(int value);
    void add_initial_value(int value);
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
    struct Node;
    Node *head;
    Node *tail;

private:

};

#endif
