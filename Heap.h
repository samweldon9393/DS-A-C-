#include <stddef.h>

class Heap{

public:

    void *head;
    size_t elements;
    size_t elementSize;
    int (*compare)(void *, void *);

    Heap(void *arr, size_t elements, size_t elementSize, int (*compare)(void *, void*));

    void printHeap(void (*print)(void *));
};

class MaxHeap : public Heap{

public:

    MaxHeap(void *arr, size_t elements, size_t elementSize, int (*compare)(void *, void *));

    // Initialize MaxHeap, return max element
    void *buildMaxHeap();

    // Create a Max Heap from a subtree
    int maxHeapify(size_t index);

    // Return top element 
    void *getMax();

    // Removes max element from the heap and returns a pointer to it 
    // The pointer points to a spot at the end of the array which could be 
    // overwritten later, so copy this data if you need it.
    void *popMax();

    // Returns a new array sorted in non-increasing order
    void *heapSort();
};
