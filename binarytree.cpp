#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

class binaryTree{
    public:

        binaryTree *left;
        binaryTree *right;
        void *data;
        size_t elementSize;

        binaryTree(void *data, size_t size){
            this->data = data;
            this->elementSize = size;
            this->left = NULL;
            this->right = NULL;
        }

        ~binaryTree(){
            free(data);
            left = NULL;
            right = NULL;
        }

        binaryTree *setLeft(void *data){
            left = new binaryTree(data, elementSize);
            return left;
        }

        binaryTree *setRight(void *data){
            right = new binaryTree(data, elementSize);
            return right;
        }

        binaryTree *linkLeft(binaryTree *newLeft){
            this->left = newLeft;
            return left;
        }

        binaryTree *linkRight(binaryTree *newRight){
            this->right = newRight;
            return right;
        }

        int dfsPrint(binaryTree *node);
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

        // Fill the tree in breadth first order with contents of arr
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

            return this; 
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

    int x[15] = {0};
    for (int i = 0 ; i< 15 ; i++){
        x[i] = i;
    }

    binaryTree *tree = new binaryTree(x, 4);

   

/*
    tree->setLeft(x+1);
    tree->setRight(x+2);

    tree->left->setLeft(x+3);
    tree->left->setRight(x+4);

    tree->right->setLeft(x+5);
    tree->right->setRight(x+6);

    tree->left->left->setLeft(x+7);
    tree->left->left->setRight(x+8);
    
    tree->left->right->setLeft(x+9);
    tree->left->right->setRight(x+10);

    tree->right->left->setLeft(x+11);
    tree->right->left->setRight(x+12);

    tree->right->right->setLeft(x+13);
    tree->right->right->setRight(x+14);
*/

    tree->bfsFill(x+1, 14);

    /* Example */ 
    printf("Should look like: \n");
    printf("%d\n", *(int *)tree->data);
    printf("%d %d\n", *(int *)tree->left->data, *(int*) tree->right->data);
    printf("%d %d ", *(int *)tree->left->left->data, *(int*) tree->left->right->data);
    printf("%d %d\n", *(int *)tree->right->left->data, *(int*) tree->right->right->data);
    printf("%d %d ", *(int *)tree->left->left->left->data, *(int*) tree->left->left->right->data);
    printf("%d %d ", *(int *)tree->left->right->left->data, *(int*) tree->left->right->right->data);
    printf("%d %d\n ", *(int *)tree->right->left->left->data, *(int *)tree->right->left->right->data);
    printf("\n\n");

    

    //printf("\n\ncalling dfsPrint: \n");
    //dfsPrint(tree);
    //printf("\n\n");
    
    
    printf("\n\ncalling bfsPrint: \n");
    tree->bfsPrint();
    
    printf("\n\ncalling dfsPrint: \n");
    tree->dfsPrint(tree);
    
}

