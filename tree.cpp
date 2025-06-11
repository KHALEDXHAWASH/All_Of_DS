#include "bits/stdc++.h"

using namespace std;


template <class T>
class BSTNode
{
private:
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
    BSTNode* getLeft ()
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

    T key;
};
template <class T>
class BST
{
protected:
    BSTNode<T>* root;
public:
    BSTNode<T>*getRoot() {
        return root;
    }
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
    void print(BSTNode<T>* p, int indent = 0) {
        if (p != 0) {
            if (p->getRight()) {
                print(p->getRight(), indent + 4);
            }
            if (indent) {
                cout << setw(indent) << ' ';
            }
            if (p->getRight()) cout << " /\n" << setw(indent) << ' ';
            cout << p->getKey() << "\n ";
            if (p->getLeft()) {
                cout << setw(indent) << ' ' << " \\\n";
                print(p->getLeft(), indent + 4);
            }
        }
    }

    void print() {
        print(root);
        cout << endl;
    }
};
template<typename T>
void bstMenu(BST<T>& bst) {
    int choice;
    T value;

    do {
        cout << "\nBST Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete by Copying\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Display Tree Structure\n";
        cout << "8. Back to main menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2: {
                cout << "Enter value to search: ";
                cin >> value;
                T* result = bst.search(value);
                if (result)
                    cout << "Value found: " << *result << endl;
                else
                    cout << "Value not found.\n";
                break;
            }
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                {
                    BSTNode<T>*& root = bst.getRoot();
                    BSTNode<T>* node = root;
                    BSTNode<T>** parentLink = &root;

                    while (node && node->getKey() != value) {
                        if (value < node->getKey()) {
                            parentLink = &(node->getLeft());
                            node = node->getLeft();
                        } else {
                            parentLink = &(node->getRight());
                            node = node->getRight();
                        }
                    }

                    if (node) {
                        bst.deleteByCopying(*parentLink);
                        cout << "Deleted.\n";
                    } else {
                        cout << "Value not found.\n";
                    }
                }
                break;
            case 4:
                bst.inorder(bst.getRoot());
                cout << endl;
                break;
            case 5:
                bst.preorder(bst.getRoot());
                cout << endl;
                break;
            case 6:
                bst.postorder(bst.getRoot());
                cout << endl;
                break;
            case 7:
                bst.print();
                break;
        }
    } while (choice != 8);
}

