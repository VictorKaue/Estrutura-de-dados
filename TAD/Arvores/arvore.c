#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int info;
    struct tree *left;
    struct tree *right;
}Tree;

Tree* findMin(Tree *tree){
    while (tree != NULL && tree->left != NULL){
        tree = tree->left;
    }
    return tree;
}

Tree* createNode(int info){
    Tree *node = (Tree *)calloc(1, sizeof(Tree));
    if (node == NULL) {
        printf("memory error\n");
        exit(1);
    }
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
    return tree;
}

Tree* deleteNodeBST(Tree *tree, int info){
    if(tree == NULL){
        return tree;
    }
    if(info < tree->info){
        return deleteNodeBST(tree->left, info);
    } else if(info > tree->info){
        return deleteNodeBST(tree->right, info);
    }else{
        if(tree->left == NULL && tree->right == NULL){
            free(tree);
            return NULL;
        } else if(tree->left == NULL){
            Tree *temp = tree->right;
            free(tree);
            return temp;
        } else if(tree->right == NULL){
            Tree *temp = tree->left;
            free(tree);
            return temp;
        }else{
            Tree *sucessor = findMin(tree->right);
            tree->info = sucessor->info;
            tree->right = deleteNodeBST(tree->right, sucessor->info);
        }
    }
    return tree;
}

void preOrder(Tree *tree){
    if(tree == NULL) return;
    printf("%d ", tree->info);
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(Tree *tree){
    if(tree == NULL) return;
    inOrder(tree->left);
    printf("%d ", tree->info);
    inOrder(tree->right);
}

void postOrder(Tree *tree){
    if(tree == NULL) return;
    postOrder(tree->left);
    postOrder(tree->right);
    printf("%d ", tree->info);
}

void destroyTree(Tree *tree){
    if(tree == NULL) return;

    destroyTree(tree->left);
    destroyTree(tree->right);

    free(tree);    
}

Tree* searchTree(Tree *tree, int info){
    if (tree == NULL || info == tree->info) return tree;
    if(info < tree->info){
        return searchTree(tree->left, info);
    } else {
        return searchTree(tree->right, info);
    }
}


Tree* findMax(Tree *tree){
    while(tree != NULL && tree->right != NULL){
        tree = tree->right;
    }
    return tree;
}

int numberofNodes(Tree *tree){
    if(tree == NULL){
        return 0;
    }
    return 1 + numberofNodes(tree->left) + numberofNodes(tree->right);
}

int main(){
    Tree *tree = createNode(100); // create the root
    tree = insert(tree, 200);
    tree = insert(tree, 150);
    tree = insert(tree, 250);
    tree = insert(tree, 50);
    tree = insert(tree, 75);
    tree = insert(tree, 120);
    tree = insert(tree, 130);
    tree = insert(tree, 300);
    tree = insert(tree, 125);
    tree = insert(tree, 110);
    deleteNodeBST(tree, 300);

    printf("preOrder: ");
    preOrder(tree);
    printf("\ninOrder: ");
    inOrder(tree);
    printf("\npostOrder: ");
    postOrder(tree);
    Tree *value_searched = searchTree(tree, 120);
    if(value_searched != NULL){
        printf("\n value found: %d", value_searched->info);
    } else {
        printf("\nNo value was found");
    }
    int number = numberofNodes(tree);
    printf("\nNumber of nodes: %d", number);
    destroyTree(tree);
    return 0;
}