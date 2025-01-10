#include <iostream>
#include "BSTree.h"

using namespace std;

BSTree::BSTree(void *data, size_t elementSize) : BinaryTree(data, elementSize){};

void BSTree::test(){
    cout << "test\n";
}

