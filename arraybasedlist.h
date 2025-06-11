//
// Created by frndas on 06/06/2025.
//
#include "bits/stdc++.h"

using namespace std;
#ifndef DSTESTS_ARRAYBASEDLIST_H
#define DSTESTS_ARRAYBASEDLIST_H
template <class T>
class arrayListType
        {
protected:
    T* list;
    int length;
    int maxSize;
public:
            arrayListType(int size)
    {
        if (size <= 0)
        {
            cerr << "Size must be positive. Setting to 100." << endl;
            maxSize = 100;
        }
        else
        {
            maxSize = size;
        }

        length = 0;
        list = new T[maxSize];
    }
    bool isEmpty() const
    {
        return(length == 0);

    }
    bool isFull()const
    {
        return (length == maxSize);
    }
    int listSize() const
    {
     return length;
    }
    int maxListSize() const
    {
     return maxSize;
    }
    void print() const
    {
        for (int i = 0; i < length; ++i)
        {
            cout << list[i]<<" ";

        }

    }
    bool isItemAtEqual(int location, const T& item) const
    {
        return (list[location]==item);
    }

    void insertAt(int location, const T& insertItem)
    {
        if (location<0||location>=maxSize)
        {
            cerr<<"suck ma balls this is ass";

        }
        else {
            if(length>= maxSize){
                cerr<<"suck ma balls again ";

            }
            else{
                for (int i = length ;i > location ; ++i)
                {
                    list [i]=list[i-1];

                }
                list[location]=insertItem;
                length++;
            }
        }
    };
    void insertEnd(const T& insertItem)
    {
        if(length>= maxSize){
            cerr<<"suck ma balls again ";

        }else{
        list[length]=insertItem;
        length++;}

    };
    void removeAt(int location)
    {if (location<0||location>=length)
        {
            cerr<<"suck ma balls this is ass";

        }else
            for (int i = location ;i <length-1 ; ++i)
                list[i]=list[i-1];
            length--;

    }
    void retrieveAt(int location, T& item) const
    {
        if (location<0||location>=length)
        {
            cerr<<"suck ma balls this is ass";

        }
        else
            item=list[location];

    }
    void replaceAt(int location, const T& repItem)
    {if (location<0||location>=length)
        {
            cerr<<"suck ma balls this is ass";

        }
        else
            list[location]=repItem;


    };
    void clearList()
    {
        length = 0;
    };

    int seqSearch(const T& item) const
    {
        int loc;
        bool found = false;

        for (loc = 0; loc < length; loc++)
            if (list[loc] == item)
            {
                found = true;
                break;
            }

        if (found)
            return loc;
        else
            return -1;
    }


    void arrayListTypeinsert(const T& insertItem)
    {
        int loc;

        if (length == 0)
            list[length++] = insertItem;
        else if (length == maxSize)
            cerr << "Cannot insert in a full list." << endl;
        else
        {
            loc = seqSearch(insertItem);
            if (loc == -1)
                list[length++] = insertItem;
            else
                cerr << "the item to be inserted is already in the list. No duplicates are allowed." << endl;
        }
    } //end insert

    void remove(const T& removeItem)
    {
        int location = seqSearch(removeItem);
        if (location != -1)
        {
            for (int i = location; i < length - 1; ++i)
            {
                list[i] = list[i + 1];
            }
            --length;
        }
        else
        {
            cerr << "Item not found in the list." << endl;
        }
    }



    arrayListType(const arrayListType<T>& otherList)
    {
        maxSize = otherList.maxSize;
        length = otherList.length;
        list = new T[maxSize];
        for (int i = 0; i < length; ++i)
        {
            list[i] = otherList.list[i];
        }
    }


    ~arrayListType()
    {
        delete[] list;
    }

    const arrayListType<T>& operator=(const arrayListType<T>& otherList)
    {
        if (this != &otherList)
        {
            delete[] list;

            maxSize = otherList.maxSize;
            length = otherList.length;
            list = new T[maxSize];

            for (int i = 0; i < length; ++i)
            {
                list[i] = otherList.list[i];
            }
        }

        return *this;
    }

};

#endif //DSTESTS_ARRAYBASEDLIST_H
