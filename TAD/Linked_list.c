#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct node{
    int data;
    struct node *next;
};

void insertAtBeginning(struct node **head_ref, int new_data);
void insertAtPosition(struct node **head_ref, int position, int new_data);
void insertAtEnd(struct node **head_ref, int new_data);
void deleteNode(struct node *head_ref, int value);
void showList(struct node *head_ref);
int sizeofList(struct node *head_ref);
void freeList(struct node *head_ref);

int main(){
    struct node *head = NULL;    
    int option, value, position;
    
    do{
        printf("\n--- Linked List Menu ---\n");
        printf("1 - Insert a node at beginning\n");
        printf("2 - Insert a node at any position\n");
        printf("3 - Insert a node at the end\n");
        printf("4 - Delete a node by value\n");
        printf("5 - Show List\n");
        printf("6 - exit\n");
        printf("Choose a option: ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert (0 for beginning): ");
                scanf("%d", &position);
                insertAtPosition(&head, position, value);
                break;
            case 3:
                printf("Enter the value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(head, value);
                break;
            case 5:
                showList(head);
                break;
            case 6:
                printf("Closing the program...\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != 6);
    printf("Closed successfully!\n");
    freeList(head);

    return 0;
}

void insertAtBeginning(struct node **head_ref, int new_data){
    struct node *new_node =  (struct node *) malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Error at alloc memory and insert at beggining!\n");
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

void insertAtPosition(struct node **head_ref, int position, int new_data){
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Error at alloc memory and insert at position!\n");
        exit(1);
    }
    new_node->data = new_data;
    
    if(head_ref == NULL && position != 0){
        printf("List is empty, can only insert at position 0.\n");
        free(new_node);
        return;
    }

    if(position == 0){
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
        return;
    }

    struct node *temp = (*head_ref);
    int i;
    for(i = 0;temp != NULL && i < position-1; i++){
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("Position is out of bounds! Please insert at the end!\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;

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
    if(head_ref == NULL){
        printf("There isn't any elements on the list");
        return;
    }

    while(temp->data == value && temp != NULL){
        head_ref = temp->next;
        free(temp);
        return;
    }
    
    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    
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
        sleep(2);
        return;
    }

    while(show != NULL){
        printf("%d -> ", show->data);
        show = show->next;
    }
    printf("NULL\n");
    printf("Size of List: %d\n", sizeofList(head_ref));
    printf("\n");
    sleep(3);
}

int sizeofList(struct node *head_ref){
    struct node *temp = head_ref;
    if(head_ref == NULL){
        return 0;
    }
    int count;
    for(count = 0; temp != NULL; count++){
        temp = temp->next;
    }
    return count;
}

void freeList(struct node *head_ref){
    struct node *temp;

    while(head_ref != NULL){
        temp = head_ref;
        head_ref = head_ref->next;
        free(temp);
    }
}
