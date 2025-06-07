//
// Created by frndas on 07/06/2025.
//

#ifndef DSTESTS_MYQUEUE_H
#define DSTESTS_MYQUEUE_H
#include "bits/stdc++.h"
template<typename T>
class LinearQueue {
private:
    int front, rear, capacity;
    T* container;

public:
    // Constructor
    LinearQueue(int size = 100) : front(0), rear(-1), capacity(size) {
        container = new T[capacity];
    }

    // Destructor
    ~LinearQueue() {
        delete[] container;
    }

    // Check if queue is empty
    bool empty() const {
        return front > rear;
    }

    // Check if queue is full
    bool full() const {
        return rear == capacity - 1;
    }

    // Get current size
    int size() const {
        return rear - front + 1;
    }

    // Add element to the back
    void enqueue(const T& value) {
        if (full()) {
            throw std::overflow_error("Queue is full");
        }
        container[++rear] = value;
    }

    // Remove element from the front
    void dequeue() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        front++;
    }

    // Get front element
    T& peek() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        return container[front];
    }
};
#endif //DSTESTS_MYQUEUE_H
