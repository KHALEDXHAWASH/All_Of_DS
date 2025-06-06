//
// Created by mario saber on 3/7/2025.
//

#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* link;
    Node(int val);
};

class SortedLinkedList {
    Node *head;

public:
    SortedLinkedList();

    void insert(int val);
    void remove(int index);

    friend ostream& operator<< (ostream& out, const SortedLinkedList& List);
    int operator[](int index);

    ~SortedLinkedList();
};



#endif //SORTEDLINKEDLIST_H
