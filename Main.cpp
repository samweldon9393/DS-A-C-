#include <stdio.h>
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

#ifdef H
#include "Heap.h"

int compare(void *x, void *y){
    return *(int *)x - *(int *)y;
}

int HeapTest(){
    int arr[30] = {0};

    for (int i = 0 ; i < 30 ; i++)
        arr[i] = 30-i;
    
    MaxHeap *heap = new MaxHeap(arr, 30, 4, &compare);

    printf("heap head: %d\n", *(int *)heap->head);

    char *it = (char *)heap->head;
    it += heap->elementSize;

    printf("element 2: %d\n", *(int *)it);

    printf("changing fist element\n");
    arr[0] = 1;

    printf("heap head: %d\n", *(int *)heap->head);
    printf("element 2: %d\n", *(int *)it);

    printf("call maxHeapify()\n");
    heap->maxHeapify(0);
    printf("heap head: %d\n", *(int *)heap->head);
    printf("element 2: %d\n", *(int *)it);

    return 0;
}
#endif

int main(){

    #ifdef H

    return HeapTest();



    #endif

}
