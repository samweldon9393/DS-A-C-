#include <stdio.h>
#include "BSTree.h"

int main(){

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
}
