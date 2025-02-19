#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int info;
    struct tree *left;
    struct tree *right;
}Tree;

Tree* createNode(int info){
    Tree *node = (Tree *)calloc(1, sizeof(Tree));
    node->info = info;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree* insert(Tree *tree, int info){
    if(tree == NULL) return createNode(info);

    if(info < tree->info){
        tree->left = insert(tree->left, info);
    } else {
        tree->right = insert(tree->right, info);
    }
}

Tree remove(){
    
}

int main(){
    Tree *tree = createNode(50); // Cria a raiz
    

    return 0;
}