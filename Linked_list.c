#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insertAtBeggining(struct node **head_ref, int new_data){
    struct node *new_node =  (struct node *) malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Error at insertAtBegginning!");
        exit(1);
    }
    
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAtEnd(struct node **head_ref, int new_data){
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Error at insertAtBegginning!");
        exit(1);
    }
    
    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;                
        return;
    }

    struct node *last = *head_ref;
    while(last != NULL){
        last = last->next;
    }
}

void freeList(struct node **head_ref){
    while((**head_ref).next != NULL){
        
    }
    
    

}


int main(){
    struct node *head = NULL;    
    int option, value;
    
    do{
        printf("\n--- Linked List Menu ---\n");
        printf("1 - insert a node at beggining\n");
        
        
        switch(option){
            case 1:
                
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                printf("Invalid option!");
                break;
        }
    } while (option != 6);

    
    return 0;
}