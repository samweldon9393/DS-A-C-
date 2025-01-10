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

Leaf::Leaf(void *data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

// Destructor
Leaf::~Leaf(){
    free(data); //bad idea?
    left = NULL;
    right = NULL;
}

// Initialize a new node, point to it with left 
// Element size must be the same as this
Leaf *Leaf::setLeft(void *data){
    left = new Leaf(data);
    return left;
}

// Initialize a new node, point to it with right 
// Element size must be the same as this
Leaf *Leaf::setRight(void *data){
    right = new Leaf(data);
    return right;
}

// Setter method for left 
// Not really needed since left is public, but cleaner
Leaf *Leaf::linkLeft(Leaf *newLeft){
    this->left = newLeft;
    return left; // Returns itself, may make some code cleaner later
}

// Setter method for right 
Leaf *Leaf::linkRight(Leaf *newRight){
    this->right = newRight;
    return right;
}

// Initialize a tree with a data pointer and and the size of the 
// data it points to (all elements must be same size or bad things)
BinaryTree::BinaryTree(void *data, size_t size){
    this->head = new Leaf(data);
    this->tail = this->head;
    this->elementSize = size;
    this->treeSize = 1;
}

Leaf *BinaryTree::addTail(void *data){
    if (this->tail->left)
        this->tail = this->tail->setRight(data);
    else 
        this->tail = this->tail->setLeft(data);
    (this->treeSize)++;
    return this->tail;
}

// Fill the tree in depth first order with contents of arr 
Leaf *BinaryTree::dfsFill(void *arr){

    if (!arr){
        return NULL;
    }

    char *it = (char *)arr;
    this->head->setLeft(arr);
    this->head->setRight(it+elementSize); 

    // TODO how do i do this lol
    return this->tail;

}

/* 
 * Fill the tree in breadth first order with contents of arr
 * @param arr - array of items to populate tree 
 * @param num - number of elements in array 
 * @return - the bottom rightmost node
 */
Leaf *BinaryTree::bfsFill(void *arr, size_t num){

    queue<Leaf *> q;
    q.push(this->head);

    char *it = (char *)arr;

    Leaf *cur;
    int j = 0;

    while (j < num){

        cur = q.front();
        q.pop();

        q.push(cur->setLeft(it));
        (this->treeSize)++;
        it += elementSize;
        if (++j >= num)
            break;

        q.push(cur->setRight(it));
        (this->treeSize)++;
        it += elementSize;
        j++;
    }

    // If there's a right node it's the last element so return it 
    // Otherwise left is the last element
    return (this->tail = cur->right ? cur->right : cur->left);
}

int BinaryTree::dfsPrintRecur(Leaf* node){

    if (node == NULL)
        return 0;
    
    printf("%d ", *(int *)node->data);

    if (dfsPrintRecur(node->left) == -1)
       cout << '\n';

    if (dfsPrintRecur(node->right) == 0)
        cout << '\n';
    return 1;
}

void BinaryTree::dfsPrint(){
    dfsPrintRecur(this->head);
}

void BinaryTree::bfsPrint(){

    unordered_map<Leaf *, bool> marked;
    queue<void *> q;
    q.push(this->head);
    int level = 1;

    //printf("%d ", *(int *)((BinaryTree *)q.front())->data);

    Leaf *cur;
    while (q.size() > 0){
        cur = (Leaf *)q.front();
        q.pop();
        if (!marked[cur]){
            printf("%d ", *(int *)((Leaf *)cur->data));
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
