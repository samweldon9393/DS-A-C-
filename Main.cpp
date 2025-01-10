#include <stdio.h>
#include "BSTree.h"

int main(){

    int x[30] = {0};
    for (int i = 0 ; i< 30 ; i++){
        x[i] = i;
    }

    BinaryTree *tree = new BinaryTree(x, 4);


    tree->bfsFill(x+1, 29);

    printf("\n\ncalling bfsPrint: \n");
    tree->bfsPrint();

    printf("\n\ncalling dfsPrint: \n");
    tree->dfsPrint(tree);

    BSTree *bstree = new BSTree(x, 4);
    bstree->test();
}
