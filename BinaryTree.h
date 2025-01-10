#include <stddef.h>

class BinaryTree{

public:
    BinaryTree *left;
    BinaryTree *right;
    void *data;
    size_t elementSize;

    // Initialize a tree with a data pointer and and the size of the
    // data it points to (all elements must be same size or bad things)
    BinaryTree(void *data, size_t size);
    ~BinaryTree();

    BinaryTree *setLeft(void *data);
    BinaryTree *setRight(void *data);

    BinaryTree *linkLeft(BinaryTree *newLeft);
    BinaryTree *linkRight(BinaryTree *newRight);

    // Depth First Search through all elements and print them
    int dfsPrint(BinaryTree *node);

    // Breadth First Search through all elements and print them
    void bfsPrint();

    // Fill the tree in depth first order with contents of arr
    BinaryTree *dfsFill(void *arr);

    /*
     * Fill the tree in breadth first order with contents of arr
     * @param arr - array of items to populate tree
     * @param num - number of elements in array
     * @return - the bottom rightmost node
     */
    BinaryTree *bfsFill(void *arr, size_t num);
};
