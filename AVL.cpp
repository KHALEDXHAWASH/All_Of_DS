#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Credentials {
    string name;
    string phone;
    string email;

    Credentials() = default;
    Credentials(const string& nm, const string& ph, const string& em) {
        name = nm;
        phone = ph;
        email = em;
    }
};

class Contact {
public:
    int key;
    Credentials data;
    int height;
    Contact *left, *right;

    Contact (const int& key, const Credentials& data) {
        this->key = key;
        this->data = data;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class AddressBook {
public:
    Contact *root;
    AddressBook() {
        this->root = nullptr;
    }

    //Tree height
    int height() {
        return root ? root->height : 0;
    }

    //Node height
    int height(const Contact* node) {
        return node ? node->height : 0;
    }

    int getBalance(const Contact* node) {
        return node ? height(node->right) - height(node->left) : 0;
    }

    Contact* rotateRight (Contact *n) {
        if (n == nullptr) {
            cerr << "Error in the tree" << endl;
        }
        else if (n->left == nullptr) {
            cerr << "Error in the tree: No right subtree to rotate." << endl;
        }
        else {
            Contact *x = n->left;
            n->left = x->right;
            x->right = n;
            n->height = 1 + max(height(n->left), height(n->right));
            x->height = 1 + max(height(x->left), height(x->right));
            return x;
        }
    }

    Contact* rotateLeft(Contact* n) {
        if (n == nullptr)
            cerr << "Error in the tree" << endl;
        else if (n->right == nullptr)
            cerr << "Error in the tree: No left subtree to rotate." << endl;
        else {
            Contact *x = n->right;
            n->right = x->left;
            x->left = n;
            n->height = 1 + max(height(n->left), height(n->right));
            x->height = 1 + max(height(x->left), height(x->right));
            return x;
        }
    }

    void insert(int key, const Credentials& data) {
        root = insert(root, key, data);
    }

    Contact* insert(Contact* node, int key, const Credentials& data) {
        if (!node) return new Contact(key, data);

        if (key < node->key)
            node->left = insert(node->left, key, data);
        else if (key > node->key)
            node->right = insert(node->right, key, data);
        else {
            cerr << "Error: Contact with ID "<< key << " already exists\n";
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance < -1 && key < node->left->key)  // Left-Left Case
            return rotateRight(node);
        if (balance > 1 && key > node->right->key)  // Right-Right Case
            return rotateLeft(node);
        if (balance < -1 && key > node->left->key) {  // Left-Right Case
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance > 1 && key < node->right->key) {  // Right-Left Case
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        cout << "Contact added.\n";
        return node;
    }

    void inOrder(const Contact* node) {
        if (node) {
            inOrder(node->left);
            cout << "ID: " << node->key <<
                  ", Name: " << node->data.name <<
                  ", Phone: " << node->data.phone <<
                  ", Email: " << node->data.email << "\n";
            inOrder(node->right);
        }
    }

    void erase(int key) {
        if (!search(key)) {
            return;
        }
        root = erase(root, key);
    }

    Contact* erase(Contact* node,const int key) {
        if (!node) return nullptr;

        if (key < node->key) {
            node->left = erase(node->left, key);
        } else if (key > node->key) {
            node->right = erase(node->right, key);
        } else {
            // Node with only one child or no child
            if (!node->left || !node->right) {
                Contact* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    // Move the content of the existing child to the node, and delete the child
                    *node = *temp;
                }
                delete temp;
            } else {
                // Node with two children: Get the predecessor
                Contact* temp = node->left;
                while (temp->right) temp = temp->right;

                node->key = temp->key;
                node->data = temp->data;
                node->left = erase(node->left, temp->key);
            }
        }

        // If the tree had only one node then return
        if (!node) return node;

        node->height = 1 + max(height(node->left), height(node->right));
        const int balance = getBalance(node);

        // Balance the tree
        if (balance > 1 && getBalance(node->right) >= 0)
            return rotateLeft(node);
        if (balance > 1 && getBalance(node->right) < 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        if (balance < -1 && getBalance(node->left) <= 0)
            return rotateRight(node);
        if (balance < -1 && getBalance(node->left) > 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        return node;
    }

    Contact* search(const int key) {
        if (!search(root,key)) {
            cout << "Contact not found.\n";
            return nullptr;
        }
        return search(root, key);
    }

    Contact* search(Contact* node, int key) {
        if (!node || node->key == key)
            return node;
        if (key < node->key)
            return search(node->left, key);
        return search(node->right, key);
    }

    void printLevel(const Contact* node,const int level,const int indent) {
        if (!node) {
            if (level == 0)
                cout << setw(indent/2) << " ";
            return;
        }
        if (level == 0) {
            cout << setw(indent/2) << node->key;
        } else {
            printLevel(node->left, level - 1, indent);
            printLevel(node->right, level - 1, indent*2);
        }
    }

    void printTree(Contact* root) {
        int h = height();
        int maxWidth = 32;
        for (int i = 0; i < h; ++i) {
            int indent = maxWidth / (1 << i);
            printLevel(root, i, indent);
            cout << endl;
        }
    }

    void displayStructure() {
        printTree(root);
    }

    void inOrderView() {
        inOrder(root);
    }

    bool isEmpty() {
        return !root;
    }

};


