#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

/* Basic implementation of a binary tree 
 */
class binaryTree{
    public:

        // Everything is public - why not it's just practice
        binaryTree *left;
        binaryTree *right;
        void *data;
        size_t elementSize;

        // Initialize a tree with a data pointer and and the size of the 
        // data it points to (all elements must be same size or bad things)
        binaryTree(void *data, size_t size){
            this->data = data;
            this->elementSize = size;
            this->left = NULL;
            this->right = NULL;
        }

        // Destructor
        ~binaryTree(){
            free(data);
            left = NULL;
            right = NULL;
        }

        // Initialize a new node, point to it with left 
        // Element size must be the same as this
        binaryTree *setLeft(void *data){
            left = new binaryTree(data, elementSize);
            return left;
        }

        // Initialize a new node, point to it with right 
        // Element size must be the same as this
        binaryTree *setRight(void *data){
            right = new binaryTree(data, elementSize);
            return right;
        }

        // Setter method for left 
        // Not really needed since left is public, but cleaner
        binaryTree *linkLeft(binaryTree *newLeft){
            this->left = newLeft;
            return left; // Returns itself, may make some code cleaner later
        }

        // Setter method for right 
        binaryTree *linkRight(binaryTree *newRight){
            this->right = newRight;
            return right;
        }

        // Methods defined outside of class 
        
        // Depth First Search through all elements and print them
        int dfsPrint(binaryTree *node);

        // Breadth First Search through all elements and print them
        void bfsPrint();

        // Fill the tree in depth first order with contents of arr 
        binaryTree *dfsFill(void *arr){
            
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
        binaryTree *bfsFill(void *arr, size_t num){
           
            queue<binaryTree *> q;
            q.push(this);

            char *it = (char *)arr;

            binaryTree *cur;
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
};

int binaryTree::dfsPrint(binaryTree *node){

    if (node == NULL)
        return 0;
    
    printf("%d ", *(int *)node->data);

    if (dfsPrint(node->left) == -1)
       cout << '\n';

    if (dfsPrint(node->right) == 0)
        cout << '\n';
    return 1;
}

void binaryTree::bfsPrint(){

    unordered_map<binaryTree *, bool> marked;
    queue<void *> q;
    q.push(this);
    int level = 1;

    //printf("%d ", *(int *)((binaryTree *)q.front())->data);

    binaryTree *cur;
    while (q.size() > 0){
        cur = (binaryTree *)q.front();
        q.pop();
        if (!marked[cur]){
            printf("%d ", *(int *)((binaryTree *)cur->data));
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

int main(){

    int x[300] = {0};
    for (int i = 0 ; i< 300 ; i++){
        x[i] = i;
    }

    binaryTree *tree = new binaryTree(x, 4);


    tree->bfsFill(x+1, 299);
    
    printf("\n\ncalling bfsPrint: \n");
    tree->bfsPrint();
    
    printf("\n\ncalling dfsPrint: \n");
    tree->dfsPrint(tree);
    
}

