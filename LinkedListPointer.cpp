//
// Created by mario saber on 3/7/2025.
//

#include "SortedLinkedList.h"

Node::Node(int val) {
    this->data = val;
    this->link = nullptr;
}

SortedLinkedList::SortedLinkedList() {
    head = nullptr;
}

void SortedLinkedList::insert(int val) {
    Node *newNode = new Node(val);

    // Check if the list or empty, or this is the smallest value to enter the list
    if (head == nullptr || head->data >= val) {
        newNode->link = head;
        head = newNode;
    }

    else {
        Node *current = head;
        while (current->link && current->link->data < val) {
            current = current->link;
        }

        newNode->link = current->link;
        current->link = newNode;
    }
}

void SortedLinkedList::remove(int index) {
    if (index < 0 || !head) {
        cerr << "Out of Range!\n";
        return;
    }

    Node *current = head;

    if (index == 0) {
        head = head->link;
        delete current;
        cout << "First Element Removed Successfully!\n";
        return;
    }

    Node* prev = nullptr;
    for (int i = 0; i < index && current ; i++) {
        prev = current;
        current = current->link;
    }

    if (!current) {
        cerr << "Out of Range!\n";
        return;
    }

    prev->link = current->link;
    delete current;
    cout << "Element with index " << index << " was removed successfully!\n";

}

int SortedLinkedList::operator[](int index) {
    Node *current = head;
    int count = 0;

    if (index < 0 || !head) {
        throw out_of_range ("Index Out of Range!");
    }

    while (current != nullptr) {
        if (count == index) return current->data;
        current = current->link;
        count++;
    }

    throw out_of_range ("Index Out of Range!");
}

ostream &operator<<(ostream &out, const SortedLinkedList &List) {
    Node *current = List.head;

    if (!current) {
        out << "[ Empty List ]";
        return out;
    }

    out << "[ ";
    while (current != nullptr) {
        out << current->data;
        if (current->link != nullptr) out << " -> ";
        current = current->link;
    }
    out << " ]";
    return out;
}


SortedLinkedList::~SortedLinkedList() {
    Node *current = head;

    while (current != nullptr) {
        Node *nextNode = current->link;
        delete current;
        current = nextNode;
    }
}






