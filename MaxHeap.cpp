#include <iostream>
using namespace std;
class MaxHeap {
private:
    int* heap;
    int size;
    int capacity;

    int parent(int i){
        return i/2;
    }
    int left(int i){
        return 2*i;
    }
    int right(int i){
        return 2*i+1;
    }
    void swap(int& a, int& b){
        a=a+b;
        b=a-b;
        a=a-b;
    };
    void heapify(int i, int size){
        int l= left(i);
        int r= right(i);
        int largest=i;
        if(l<=size && heap[i]<heap[l])
            largest=l;
        if(r<=size && heap[largest]<heap[r])
            largest=r;

        swap(heap[i],heap[largest]);
        if(largest==i)
            return;
        else
            heapify(largest,size);
    }
    void build_heap(){
        for(int i=size/2;i>=1;i--)
            heapify(i,size);
    }

    void bubbleUp(int i) {
        while (i > 1 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }


public:
    MaxHeap(int capacity):capacity(capacity),size(0){
        heap= new int[capacity+1];
    }

    ~MaxHeap(){
        delete []heap;
    }

    void insert(int key){
        if (size >= capacity) return;
        heap[++size]=key;
        bubbleUp(size);
    }
    int extractMax(){
        if(size==0) return -1;
        int max=heap[1];
        heap[1]=heap[size--];
        heapify(1);
        return max;
    }
    void increaseKey(int i, int newKey){
        heap[i]=newKey;
        bubbleUp(i);
    }
    void heapSort(int arr[], int n) {
        build_heap();
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(0,i-1);
        }
    }
    int getMax(){
        return heap[1];
    }
    bool isEmpty() const{
        return !size;
    }
    int getSize() const{
        return size;
    }
    void printHeap(int i=1){
        printHeap(left(i));
        cout<<heap[i]<<" ";
        printHeap(right(i));
    }
};
