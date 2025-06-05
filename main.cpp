#include "sorting.cpp"
#include "tree.cpp"
using namespace std;
////void swapwithouttemp (int x , int y)
//{
//    x=x+y;
//    y=x-y;
//    x=x-y;
//
//}
void run() {
    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;

    SortingSystem<int> sorter(n);

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

}
int main()
{
    run();
}
