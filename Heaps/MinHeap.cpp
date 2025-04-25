#include <iostream>
using namespace std;

class MinHeap {
private:
    int *arr;
    int capacity;
    int size;
public:
    MinHeap(int cap) : capacity(cap), size(0) {
        arr = new int[cap];
    }

    void insert(int k) {
        if (size == capacity) return; // max size

        // put the new value
        arr[++size] = k;
        percolateUp(size);
    }

    void percolateUp(int i) {
        if (i <= 1) return; // this is the root

        // compare against parent
        if (arr[i/2] > arr[i]) {
            swap(i, i/2);
            // check if it must be down to the parent now
            percolateUp(i/2);
        }
    }

    void swap(int child, int parent) {
        int temp = arr[child];
        arr[child] = arr[parent];
        arr[parent] = temp;
    }

    int extractMin() {
        if (size <= 0) return -1;
        int val = arr[1];
        arr[1] = arr[size--];
        percolateDown(1);
        return val;
    }

    void percolateDown(int i) {
        int min;

        if ((2*i+1) <= size) { // internal nodes
            min = minimum(arr[2 * i], 2 * i, arr[2 * i + 1], 2 * i + 1);

            if (arr[i] > arr[min]) {
                swap(i, min); // swap if num on top is bigger
                percolateDown(min); // recurse
            }
        }
        else if (2*i == size) { // has only left child
            if (arr[i] > arr[2 * i])
                swap(i, 2 * i); // no need to recurse, this is last node.
        }
    }

    int minimum(int a, int indexa, int b, int indexb) {
        if (a < b)
            return indexa;
        else
            return indexb;
    }

    MinHeap* initHeapFromArray(int *values, int length) {
        MinHeap *h = new MinHeap(length);
        // Just copy the values into our array.
        for (int i = 1; i <= length; i++)
            h->arr[i] = values[i - 1];
        // This is the number of values we copied.
        h->size = length;
        // This takes our random values and rearranges them into a heap.
        h->Heapify();
        return h;
    }

    void Heapify() { // run percolate down on first half of array (all but leaf nodes)
        for (int i = size/2; i > 0; i--)
            percolateDown(i);
    }
};

void sort(int values[], int len) {
    MinHeap *h = new MinHeap(len);

    h = h->initHeapFromArray(values, len);

    for (int i = 0; i < len; i++) {
        values[i] = h->extractMin();
        cout << "array[" << i << "]: " << values[i] << endl;
    }
}

int main() {
    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    cout << "Min value:" << h.extractMin() << "\n";
    cout << "Min value:" << h.extractMin() << "\n";
    cout << "Min value:" << h.extractMin() << "\n";
    cout << "Min value:" << h.extractMin() << "\n";
    cout << "Min value:" << h.extractMin() << "\n";
    cout << "Min value:" << h.extractMin() << "\n";
    h.insert(7);
    h.insert(21);
    h.insert(5);
    cout << "Min value:" << h.extractMin() << "\n";
    cout << "Min value:" << h.extractMin() << "\n";
    cout << "Min value:" << h.extractMin() << "\n";

    int unSortedArr[7] = {4, 2, 12, 54, 23, 3, 100};
    cout << "After heapSort:\n";
    sort(unSortedArr, 7);
    
    return 0;
}