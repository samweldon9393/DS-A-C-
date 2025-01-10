#include "Heap.h"

Heap::Heap(void *arr, size_t elements, size_t size, int (*compare)(void*, void*)){
    this->head = arr;
    this->elements = elements;
    this->elementSize = size;
    this->compare = compare;
}
