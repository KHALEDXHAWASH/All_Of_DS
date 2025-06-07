//
// Created by frndas on 07/06/2025.
//

#ifndef DSTESTS_QUEUEBUTCIRCULAR_H
#define DSTESTS_QUEUEBUTCIRCULAR_H
#include "bits/stdc++.h"

template<typename T>

class CircularQueue {
private:
    int front, rear, size, capacity;
    T* container;

public:
    // Constructor
    CircularQueue(int size = 100) : front(0), rear(-1), size(0), capacity(size) {
        container = new T[capacity];
    }

    // Destructor
    ~CircularQueue() {
        delete[] container;
    }

    // Check if queue is empty
    bool empty() const {
        return size == 0;
    }

    // Check if queue is full
    bool full() const {
        return size == capacity;
    }

    // Get current size
    int getSize() const {
        return size;
    }

    // Add element to the back
    void enqueue(const T& value) {
        if (full()) {
            throw std::overflow_error("Queue is full");
        }
        rear = (rear + 1) % capacity;
        container[rear] = value;
        size++;
    }

    // Remove element from the front
    void dequeue() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        front = (front + 1) % capacity;
        size--;
    }

    // Get front element
    T& peek() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        return container[front];
    }
};
#endif //DSTESTS_QUEUEBUTCIRCULAR_H
