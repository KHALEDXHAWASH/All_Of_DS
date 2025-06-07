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

    void breadthfirst()
    {
        queue<BSTNode<T>*>queue;
        BSTNode<T> *p = root;
        if (p!=0)
        {
            queue.enqueue(p);
            while(!queue.isEmpty())
            {
            p=queue.dequeue();
                visit(p);
                if (p->left !=0)
                {
                    queue.enqueue(p);

                }if (p->right !=0)
                {
                    queue.enqueue(p);

                }

            }

        }

    }
    void inorder(BSTNode<T>*p)
    {
        if (p!=0)
        {
            inorder(p->left);
            visit(p);
            inorder(p->right);

        }
    } void preorder(BSTNode<T>*p)
    {
        if (p!=0)
        {
            visit(p);

            preorder(p->left);
            preorder(p->right);

        }
    } void postorder(BSTNode<T>*p)
    {
        if (p!=0)
        {

            postorder(p->left);
            postorder(p->right);
            visit(p);

        }
    }
    void insert(T& element)
    {
        // Check if tree is empty (root is null)
        if (root == 0)
        {
            // If empty, create new node with the element and make it root
            root = new BSTNode<T>(element);
        }
        else
        {
            // Initialize traversal pointers:
            // p - current node being examined (starts at root)
            // prev - parent of current node (starts null)
            BSTNode<T> *p = root, *prev = 0;

            // Traverse the tree to find insertion position
            while(p != 0)
            {
                // Update prev to be current node before moving down
                prev = p;

                // Compare element with current node's key
                if(element < p->key)  // If element is smaller
                {
                    p = p->left;    // Move to left child
                }
                else if(element > p->key)  // If element is larger
                {
                    p = p->right;   // Move to right child
                }
                else
                {
                    // Element already exists in tree (duplicate)
                    // Simply return without inserting
                    return;
                }
            }

            // Found insertion position (p is null, prev is parent)
            // Create new node as either left or right child of prev
            if(element < prev->key)
            {
                prev->left = new BSTNode<T>(element);  // Insert as left child
            }
            else
            {
                prev->right = new BSTNode<T>(element); // Insert as right child
            }
        }
    }
   void deleteByCopying(BSTNode<T>*& node)
   {
    BSTNode<T> *prev, *tmp = node;

    if (node->right == 0) // node has no right child
    {
        node = node->left;
    }
    else if (node->left == 0) // node has no left child
    {
        node = node->right;
    }
    else// node has both children
    {
        tmp = node->left;         // start with left subtree
        prev = node;              // keep track of previous node

        while (tmp->right != 0)  // find rightmost node (predecessor)
        {
            prev = tmp;
            tmp = tmp->right;
        }

        node->key = tmp->key;     // copy predecessor's value

        if (prev == node)    // if predecessor is deeper in left subtree
        {
            prev->left = tmp->left;
        }
        else  // if predecessor is direct left child
        {
            prev->right = tmp->left;
        }
    }
    delete tmp;                  // delete the copied node
}
};