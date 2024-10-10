#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct node{
    int data;
    struct node *next;
};

void insertAtBeginning(struct node **head_ref, int new_data);
void insertAtPosition(struct node *head_ref, int position, int new_data);
void insertAtEnd(struct node **head_ref, int new_data);
void deleteNode(struct node *head_ref, int value);
void showList(struct node *head_ref);
void freeList(struct node *head_ref);
void clearScreen();

int main(){
    struct node *head = NULL;    
    int option, value;
    
    do{
        clearScreen();
        printf("\n--- Linked List Menu ---\n");
        printf("1 - Insert a node at beginning\n");
        printf("3 - Insert a node at any position");
        printf("2 - Insert a node at the end\n");
        printf("3 - Delete a node by value\n");
        printf("4 - Show List\n");
        printf("5 - exit\n");
        printf("Choose a option: ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                printf("Insert the value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Insert the value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Insert the value to delete: ");
                scanf("%d", &value);
                deleteNode(head, value);
                break;
            case 4:
                showList(head);
                break;
            case 5:
                printf("Closing the program...\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != 5);
    printf("Closed successfully!\n");
    freeList(head);

    return 0;
}

void insertAtBeginning(struct node **head_ref, int new_data){
    struct node *new_node =  (struct node *) malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Error at alloc memory and insert at beggining!");
        exit(1);
    }

    if((*head_ref) == NULL){
        new_node->data = new_data;
        new_node->next = NULL;
        (*head_ref) = new_node;
        return;
    }
    
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAtPosition(struct node *head_ref, int position, int new_data){


}

void insertAtEnd(struct node **head_ref, int new_data){
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Error at alloc memory and insert at end!");
        exit(1);
    }

    new_node->data = new_data;
    new_node->next = NULL;
    
    if((*head_ref) == NULL){
        (*head_ref) = new_node;
        return;
    }
    
    struct node *last = *head_ref;
    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
}

void deleteNode(struct node *head_ref, int value){
    struct node *temp = head_ref, *prev;

    while(temp->data == value && temp != NULL){
        head_ref = temp->next;
        free(temp);
        return;
    }
    
    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }clearScreen();
    
    if(temp == NULL){
        printf("This value don't exist in the list!");
        return;
    }

    prev->next = temp->next;
    free(temp);    
}


void showList(struct node *head_ref){
    struct node *show = head_ref;
    
    if(show == NULL){
        printf("The list is empty\n");
    }

    while(show != NULL){
        printf("%d -> ", show->data);
        show = show->next;
    }
    printf("NULL\n");
    sleep(3);
}

void freeList(struct node *head_ref){
    struct node *temp;

    while(head_ref != NULL){
        temp = head_ref;
        head_ref = head_ref->next;
        free(temp);
    }
}

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #elif _WIN64
        system("cls");
    #else
        system("clear");
    #endif
}
