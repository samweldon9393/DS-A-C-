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

        binaryTree(void *data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

        ~binaryTree(){
            free(data);
            left = NULL;
            right = NULL;
        }

        void setLeft(void *data){
            left = new binaryTree(data);
        }

        void setRight(void *data){
            right = new binaryTree(data);
        }
};

void dfsPrint(binaryTree *node){

    if (node == NULL)
        return;
    
    printf("%d ", *(int *)node->data);

    dfsPrint(node->left);
    cout << "\n";
    dfsPrint(node->right);
}

void bfsPrintRecur(binaryTree *node){
    
    // Print node 
    printf("%d ", *(int *)node->data);

    // Print both children
    
}

void bfsPrint(binaryTree *node){

    unordered_map<binaryTree *, bool> marked;
    queue<void *> q;
    q.push(node);
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

    int x[12] = {0};
    for (int i = 0 ; i< 12 ; i++){
        x[i] = i;
    }

    binaryTree *tree = new binaryTree(x);

   


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

    /* Example */ 
    printf("Should look like: \n");
    printf("%d\n", *(int *)tree->data);
    printf("%d %d\n", *(int *)tree->left->data, *(int*) tree->right->data);
    printf("%d %d ", *(int *)tree->left->left->data, *(int*) tree->left->right->data);
    printf("%d %d\n", *(int *)tree->right->left->data, *(int*) tree->right->right->data);
    printf("%d %d ", *(int *)tree->left->left->left->data, *(int*) tree->left->left->right->data);
    printf("%d %d ", *(int *)tree->left->right->left->data, *(int*) tree->left->right->right->data);
    printf("%d \n ", *(int *)tree->right->left->left->data);
    printf("\n\n");

    

    //printf("\n\ncalling dfsPrint: \n");
    //dfsPrint(tree);
    //printf("\n\n");
    
    
    printf("\n\ncalling bfsPrint: \n");
    bfsPrint(tree);
    
}

