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

/*TODO get this to work for other data types
 * 0                        2 
 * 1 2                      3 4
 * 3 4 5 6                  5 6 7 8 
 * 7 8 9 10 11 12 13 14     9 10 11 12 13 14 15 16
 */ 
void Heap::printHeap(){
    int power = 1;
    for (int i = 0 ; i < this->elements ; i++){
        printf("%d ", ((int *)this->head)[i]);
        if (i+2 == pow(2, power)){
            putchar('\n');
            power++;
        }
    }
} 

MaxHeap::MaxHeap(void *arr, size_t elements, size_t size, int (*compare)(void*, void*)) :
    Heap(arr, elements, size, compare){};

void *MaxHeap::buildMaxHeap(){


    
}

void MaxHeap::maxHeapify(size_t index){

    // Indexed at 1 works better for the math in this part of the function
    index++;

    int level = log2(index);
    int nodesOnLevel = pow(2, level);
    
    // If we're on the lowest level, it's lead and therefor already a max heap
    if (log2(this->elements) == level)
        return;

    int leftChild = index + (index - nodesOnLevel) + nodesOnLevel - 1;
    int rightChild = leftChild + 1;

    char *it = (char *)this->head;

    // Actual 0 indexing is needed for this part TODO maybe?
    index--;

    int biggerChild, smallerChild;
    if (this->compare(it+(elementSize * leftChild), it+(elementSize * rightChild)) > 0){
        biggerChild = leftChild;
        smallerChild = rightChild;
    } else {
        biggerChild = rightChild;
        smallerChild = leftChild;
    }

    void *temp = malloc(elementSize);
    if (this->compare(it+(index * elementSize), it+(biggerChild * elementSize)) < 0){
        memcpy(temp, it+(index * elementSize), elementSize);
        memcpy(it+(index * elementSize), it+(biggerChild * elementSize), elementSize);
        memcpy(it+(biggerChild * elementSize), temp, elementSize);
    }
    free(temp);
}
