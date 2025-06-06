#include <iostream>
using namespace std;

#include "arraybasedlist.h"
#include "stack.h"
#include "sorting.cpp" // Assume it's implemented or ask me to write it

template<typename T>
void arrayListMenu() {
    int size;
    cout << "Enter the size of the list: ";
    cin >> size;
    arrayListType<T> list(size);

    int choice, item, location;
    do {
        cout << "\nArray List Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Insert at location\n";
        cout << "3. Remove item\n";
        cout << "4. Remove at location\n";
        cout << "5. Print list\n";
        cout << "6. Back to main menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to insert: ";
                cin >> item;
                list.arrayListTypeinsert(item);
                break;
            case 2:
                cout << "Enter location and item: ";
                cin >> location >> item;
                list.insertAt(location, item);
                break;
            case 3:
                cout << "Enter item to remove: ";
                cin >> item;
                list.remove(item);
                break;
            case 4:
                cout << "Enter location to remove at: ";
                cin >> location;
                list.removeAt(location);
                break;
            case 5:
                list.print();
                cout << endl;
                break;
        }
    } while (choice != 6);
}

template<typename T>
void stackMenu() {
    Stack<T> stack;
    int choice, item;

    do {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Print stack\n";
        cout << "6. Back to main menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to push: ";
                cin >> item;
                stack.push(item);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Top item: " << stack.top() << endl;
                break;
            case 4:
                cout << "Stack size: " << stack.size() << endl;
                break;
            case 5:
                cout << stack << endl;
                break;
        }
    } while (choice != 6);
}

template<typename T>
void sortingMenu() {
    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;
    SortingSystem<T> sorter(n);

    cout << "\nChoose sorting algorithm:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Shell Sort\n";
    cout << "5. Merge Sort\n";
    cout << "6. Quick Sort\n";
    cout << "7. Counting Sort\n";
    cout << "8. Radix Sort\n";
    cout << "9. Bucket Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            sorter.insertionSort();
            break;
        case 2:
            sorter.selectionSort();
            break;
        case 3:
            sorter.bubbleSort();
            break;
        case 4:
            sorter.shellSort();
            break;
        case 5:
            sorter.mergeSort();
            break;
        case 6:
            sorter.quickSort();
            break;
        case 7:
            sorter.countSort();
            break;
        case 8:
            sorter.radixSort();
            break;
        case 9:
            sorter.bucketSort();
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }

    cout << "Sorted array: ";
    printarray(sorter.getData(), n);
    cout << endl;
}

int main() {
    int mainChoice;
    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Array-Based List\n";
        cout << "2. Stack\n";
        cout << "3. Sorting System\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                arrayListMenu<int>();
                break;
            case 2:
                stackMenu<int>();
                break;
            case 3:
                sortingMenu<int>();
                break;
            case 4:
                cout << "TJA\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (mainChoice != 4);

    return 0;
}
