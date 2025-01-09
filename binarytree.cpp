#include <stdio.h>
#include <stdlib.h>

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
    dfsPrint(node->right);
}

int main(){

    int x[15] = {0};
    for (int i = 0 ; i< 15 ; i++){
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
    tree->right->left->setRight(x+12);
    
    tree->right->right->setLeft(x+13);
    tree->right->right->setRight(x+14);
   

    /* Example */ 
    printf("Should look like: \n");
    printf("%d\n", *(int *)tree->data);
    printf("%d %d\n", *(int *)tree->left->data, *(int*) tree->right->data);
    printf("%d %d ", *(int *)tree->left->left->data, *(int*) tree->left->right->data);
    printf("%d %d\n", *(int *)tree->right->left->data, *(int*) tree->right->right->data);
    printf("%d %d ", *(int *)tree->left->left->left->data, *(int*) tree->left->left->right->data);
    printf("%d %d ", *(int *)tree->left->right->left->data, *(int*) tree->left->right->right->data);
    printf("%d %d ", *(int *)tree->right->left->left->data, *(int*) tree->right->left->right->data);
    printf("%d %d\n", *(int *)tree->right->right->left->data, *(int*) tree->right->right->right->data);
    printf("\n\n");

    printf("\n\ncalling dfsPrint: \n");
    dfsPrint(tree);
    printf("\n\n");
}

