//
// Created by frndas on 06/06/2025.
//

#ifndef DSTESTS_STACK_H
#define DSTESTS_STACK_H

#include <iostream>

template <typename T>
class Stack
{
protected:
    T* data;
    int topIndex;
    int capacity;

    void resize()
    {
        int newCapacity = capacity * 2;
        T* newData = new T[newCapacity];

        for (int i = 0; i < capacity; ++i)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Stack(int initialSize = 100)
    {
        capacity = initialSize;
        data = new T[capacity];
        topIndex = -1;
    }

    ~Stack()
    {
        delete[] data;
    }

    void push(const T& value)
    {
        if (topIndex + 1 >= capacity)
        {
            resize();
        }
        data[++topIndex] = value;
    }

    void pop()
    {
        if (!empty())
        {
            --topIndex;
        }
    }

    T& top()
    {
        return data[topIndex];
    }

    const T& top() const
    {
        return data[topIndex];
    }

    int size() const
    {
        return topIndex + 1;
    }

    bool empty() const
    {
        return topIndex == -1;
    }

    void clear()
    {
        topIndex = -1;
    }

    friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack)
    {
        os << "[";
        for (int i = 0; i <= stack.topIndex; ++i)
        {
            os << stack.data[i];
            if (i != stack.topIndex)
                os << ", ";
        }
        os << "]";
        return os;
    }
};

#endif //DSTESTS_STACK_H
