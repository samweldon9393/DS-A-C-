#include <stddef.h>

class Leaf{

public:
    void *data;
    Leaf *left;
    Leaf *right;

    Leaf(void *data);
    ~Leaf();

    Leaf *setLeft(void *data);
    Leaf *setRight(void *data);

    Leaf *linkLeft(Leaf *newLeft);
    Leaf *linkRight(Leaf *newRight);

};

class BinaryTree{

public:

    Leaf *head;
    Leaf *tail;
    size_t elementSize;
    size_t treeSize;

    // Initialize a tree with a data pointer and and the size of the
    // data it points to (all elements must be same size or bad things)
    BinaryTree(void *data, size_t size);
    ~BinaryTree();

    Leaf *addTail(void *data);
    
    // Depth First Search through all elements and print them
    int dfsPrintRecur(Leaf *node);
    void dfsPrint();

    // Breadth First Search through all elements and print them
    void bfsPrint();

    // Fill the tree in depth first order with contents of arr
    Leaf *dfsFill(void *arr);

    /*
     * Fill the tree in breadth first order with contents of arr
     * @param arr - array of items to populate tree
     * @param num - number of elements in array
     * @return - the bottom rightmost node
     */
    Leaf *bfsFill(void *arr, size_t num);
};
