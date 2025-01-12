#include <stddef.h>

class Heap{

public:

    void *head;
    size_t elements;
    size_t elementSize;
    int (*compare)(void *, void *);

    Heap(void *arr, size_t elements, size_t elementSize, int (*compare)(void *, void*));

    void printHeap();
};

class MaxHeap : public Heap{

public:

    MaxHeap(void *arr, size_t elements, size_t elementSize, int (*compare)(void *, void *));

    // Initialize MaxHeap, return max element
    void *buildMaxHeap();

    void maxHeapify(size_t index);
};
