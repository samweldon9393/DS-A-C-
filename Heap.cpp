#include <cmath>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "Heap.h"

Heap::Heap(void *arr, size_t elements, size_t size, int (*compare)(void*, void*)){
    this->head = arr;
    this->elements = elements;
    this->elementSize = size;
    this->compare = compare;
}

/* Type agnostinc Heap printer
 * @param print - pass a pointer to print function.
 */ 
void Heap::printHeap(void (*print)(void *)){
    int power = 1;
    char *it = (char *)this->head;
    for (int i = 0 ; i < this->elements ; i++){
        print(it+(i*elementSize));
        if (i+2 == pow(2, power)){
            putchar('\n');
            power++;
        }
    }
    putchar('\n');
} 

MaxHeap::MaxHeap(void *arr, size_t elements, size_t size, int (*compare)(void*, void*)) :
    Heap(arr, elements, size, compare){};

void *MaxHeap::buildMaxHeap(){

    int rows = 0;

    while (pow(2, ++rows) <= elements);

    int first = pow(2, rows-1) - 2;

    for (int i = first ; i >= 0 ; i--){
        int j = i;
        while (j <= first)
            j = maxHeapify(j);
    }
    return this->head;
}

int MaxHeap::maxHeapify(size_t index){

    // Indexed at 1 works better for the math in this part of the function
    index++;

    int level = log2(index);
    int nodesOnLevel = pow(2, level);
    
    // If we're on the lowest level, it's a leaf and therefor a max heap
    // Return value always high enough to break loop in buildMaxHeap
    if (log2(this->elements) == level)
        return elements + 1;

    int leftChild = index + (index - nodesOnLevel) + nodesOnLevel - 1;
    int rightChild = leftChild + 1;

    char *it = (char *)this->head;

    // Actual 0 indexing is needed for this part 
    index--;

    int biggerChild;
    if (leftChild >= elements)
        return elements + 1;                             // We're on a leaf
    else if (rightChild >= elements ||      // Node only has a left child
            this->compare(it+(elementSize * leftChild), it+(elementSize * rightChild)) > 0){
        biggerChild = leftChild;
    } else {
        biggerChild = rightChild;
    }

    void *temp = malloc(elementSize);
    if (this->compare(it+(index * elementSize), it+(biggerChild * elementSize)) < 0){
        memcpy(temp, it+(index * elementSize), elementSize);
        memcpy(it+(index * elementSize), it+(biggerChild * elementSize), elementSize);
        memcpy(it+(biggerChild * elementSize), temp, elementSize);
    }
    free(temp);

    return biggerChild;
}

void *MaxHeap::getMax(){
    return this->head;
}

void *MaxHeap::popMax(){
    void *temp = malloc(elementSize);
    char *last = (char *)this->head;
    last += (elements - 1) * elementSize;
    
    memcpy(temp, this->head, elementSize);
    memcpy(this->head, last, elementSize);
    memcpy(last, temp, elementSize);

    elements--;

    this->buildMaxHeap();

    return last;
}

void *MaxHeap::heapSort(){
    void *arr = malloc(elements * elementSize);
    char *it = (char *)arr;

    while (elements > 0){
        memcpy(it, this->popMax(), elementSize);
        it += elementSize;
    }

    return arr;
}

/*
 * Min Heap 
 */

MinHeap::MinHeap(void *arr, size_t elements, size_t size, int (*compare)(void*, void*)) :
    Heap(arr, elements, size, compare){};

void *MinHeap::buildMinHeap(){

    int rows = 0;

    while (pow(2, ++rows) <= elements);

    int first = pow(2, rows-1) - 2;

    for (int i = first ; i >= 0 ; i--){
        int j = i;
        while (j <= first)
            j = minHeapify(j);
    }
    return this->head;
}

int MinHeap::minHeapify(size_t index){

    // Indexed at 1 works better for the math in this part of the function
    index++;

    int level = log2(index);
    int nodesOnLevel = pow(2, level);
    
    // If we're on the lowest level, it's a leaf and therefor a max heap
    // Return value always high enough to break loop in buildMaxHeap
    if (log2(this->elements) == level)
        return elements + 1;

    int leftChild = index + (index - nodesOnLevel) + nodesOnLevel - 1;
    int rightChild = leftChild + 1;

    char *it = (char *)this->head;

    // Actual 0 indexing is needed for this part 
    index--;

    int smallerChild;
    if (leftChild >= elements)
        return elements + 1;                             // We're on a leaf
    else if (rightChild >= elements ||      // Node only has a left child
            this->compare(it+(elementSize * leftChild), it+(elementSize * rightChild)) < 0){
        smallerChild = leftChild;
    } else {
        smallerChild = rightChild;
    }

    void *temp = malloc(elementSize);
    if (this->compare(it+(index * elementSize), it+(smallerChild * elementSize)) > 0){
        memcpy(temp, it+(index * elementSize), elementSize);
        memcpy(it+(index * elementSize), it+(smallerChild * elementSize), elementSize);
        memcpy(it+(smallerChild * elementSize), temp, elementSize);
    }
    free(temp);

    return smallerChild;
}

void *MinHeap::getMin(){
    return this->head;
}

void *MinHeap::popMin(){
    void *temp = malloc(elementSize);
    char *last = (char *)this->head;
    last += (elements - 1) * elementSize;
    
    memcpy(temp, this->head, elementSize);
    memcpy(this->head, last, elementSize);
    memcpy(last, temp, elementSize);

    elements--;

    this->buildMinHeap();

    return last;
}

void *MinHeap::heapSort(){
    void *arr = malloc(elements * elementSize);
    char *it = (char *)arr;

    while (elements > 0){
        memcpy(it, this->popMin(), elementSize);
        it += elementSize;
    }

    return arr;
}

