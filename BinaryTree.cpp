#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>

#include "BinaryTree.h"

using namespace std;

/* Basic implementation of a binary tree 
 */

// Initialize a tree with a data pointer and and the size of the 
// data it points to (all elements must be same size or bad things)
BinaryTree::BinaryTree(void *data, size_t size){
    this->data = data;
    this->elementSize = size;
    this->left = NULL;
    this->right = NULL;
}

// Destructor
BinaryTree::~BinaryTree(){
    free(data);
    left = NULL;
    right = NULL;
}

// Initialize a new node, point to it with left 
// Element size must be the same as this
BinaryTree *BinaryTree::setLeft(void *data){
    left = new BinaryTree(data, elementSize);
    return left;
}

// Initialize a new node, point to it with right 
// Element size must be the same as this
BinaryTree *BinaryTree::setRight(void *data){
    right = new BinaryTree(data, elementSize);
    return right;
}

// Setter method for left 
// Not really needed since left is public, but cleaner
BinaryTree *BinaryTree::linkLeft(BinaryTree *newLeft){
    this->left = newLeft;
    return left; // Returns itself, may make some code cleaner later
}

// Setter method for right 
BinaryTree *BinaryTree::linkRight(BinaryTree *newRight){
    this->right = newRight;
    return right;
}


// Fill the tree in depth first order with contents of arr 
BinaryTree *BinaryTree::dfsFill(void *arr){

    if (!arr){
        return NULL;
    }

    char *it = (char *)arr;
    this->setLeft(arr);
    this->setRight(it+elementSize); 

    // TODO how do i do this lol
    return this;

}

/* 
 * Fill the tree in breadth first order with contents of arr
 * @param arr - array of items to populate tree 
 * @param num - number of elements in array 
 * @return - the bottom rightmost node
 */
BinaryTree *BinaryTree::bfsFill(void *arr, size_t num){

    queue<BinaryTree *> q;
    q.push(this);

    char *it = (char *)arr;

    BinaryTree *cur;
    int j = 0;

    while (j < num){

        cur = q.front();
        q.pop();

        q.push(cur->setLeft(it));
        it += elementSize;
        if (++j >= num)
            break;

        q.push(cur->setRight(it));
        it += elementSize;
        j++;
    }

    // If there's a right node it's the last element so return it 
    // Otherwise left is the last element
    return cur->right ? cur->right : cur->left;
}

int BinaryTree::dfsPrint(BinaryTree *node){

    if (node == NULL)
        return 0;
    
    printf("%d ", *(int *)node->data);

    if (dfsPrint(node->left) == -1)
       cout << '\n';

    if (dfsPrint(node->right) == 0)
        cout << '\n';
    return 1;
}

void BinaryTree::bfsPrint(){

    unordered_map<BinaryTree *, bool> marked;
    queue<void *> q;
    q.push(this);
    int level = 1;

    //printf("%d ", *(int *)((BinaryTree *)q.front())->data);

    BinaryTree *cur;
    while (q.size() > 0){
        cur = (BinaryTree *)q.front();
        q.pop();
        if (!marked[cur]){
            printf("%d ", *(int *)((BinaryTree *)cur->data));
            marked[cur] = true;
            if (!marked.count(cur->left) && cur->left != NULL)
                q.push(cur->left);
            if (!marked.count(cur->right) && cur->right != NULL)
                q.push(cur->right);
        }
            
        if (pow(2, level) == marked.size() + 1 ){
            level++;
            putchar('\n');
        }
    }
}
