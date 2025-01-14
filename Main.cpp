#include <stdio.h>
#include <iostream>
#include <cmath>

#ifdef BT
#include "BSTree.h"
int BinaryTreeTest(){

    int x[30] = {0};
    for (int i = 0 ; i< 30 ; i++){
        x[i] = i+1;
    }

    BinaryTree *tree = new BinaryTree(x, 4);
    printf("tree->head: %d\n", *(int *)tree->head->data);


    tree->bfsFill(x+1, 29);

    printf("bfsPrint: \n");
    tree->bfsPrint();

    printf("\ntree->head: %d\n", *(int *)tree->head->data);
    printf("tree->tail: %d\n", *(int *)tree->tail->data);

    printf("adding to tail:\n");
    int y = 50;
    tree->addTail(&y);
    tree->bfsPrint();
    printf("\ntree->head: %d\n", *(int *)tree->head->data);
    printf("tree->tail: %d\n", *(int *)tree->tail->data);

    //BSTree *bstree = new BSTree(x, 4);
    //bstree->test();
    
    return 0;
}
#endif

#include "Heap.h"
#ifdef H
int compare(void *x, void *y){
    return *(int *)x - *(int *)y;
}

void printInt(void *x){
    printf("%d ", *(int *)x);
}

int HeapTest(){
    int size = 15;
    int *arr = (int *)malloc(sizeof(int) * size);

    for (int i = 0 ; i < size ; i++)
        arr[i] = i;
    
    MaxHeap *heap = new MaxHeap(arr, size, 4, &compare);

    heap->printHeap(&printInt);

    std::cout <<"\ncalleing buildMaxHeap\n";
    heap->buildMaxHeap();
    heap->printHeap(&printInt);

    std::cout << "\ncalling heapSort\n";

    int *sorted = (int *)heap->heapSort();
    for (int i = 0 ; i < size ; i++){
        std::cout << *(sorted + i);
        std::cout << " ";
    }
    std::cout << '\n';

    return 0;
}
#endif

int main(){

    #ifdef H

    return HeapTest();



    #endif

}
