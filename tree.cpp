#include "bits/stdc++.h"

using namespace std;


template <class T>
class BSTNode
{
private:
    T key;
    BSTNode* left;
    BSTNode* right;
public:
    BSTNode ()
    {
        left = right = 0;
    }
    BSTNode (T& el, BSTNode* l = 0, BSTNode* r = 0)
    {
        key= el;
        left  = l;
        right = r;
    }
    BSTNode* getLeft  ()
    {
        return left;
    }
    BSTNode* getRight()
    {
        return right;
    }
    T getKey()
    {
        return key;
    }

};
template <class T>
class BST
{
protected:
    BSTNode<T>* root;
public:
    BST ();
    void clear()
    {
        root = 0;
    }
    bool isEmpty()
    {
        return root == 0;
    }
    T* search (T& el)
    {
        BSTNode<T>* p = root;
        while (p != 0)
        {
            if (el == p->getKey())
                return &p->getKey();
            else if (el < p->getKey())
            {
                p -> getLeft();
            }
            else p -> getRight();
            return 0;
        }
    }
};