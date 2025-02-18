#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int info;
    struct tree *left;
    struct tree *right;
}Tree;

Tree createTree(){
    Tree *tree = (Tree *)calloc(1, sizeof(Tree));
    
}

int main(){
    Tree tree = createTree();
    return 0;
}