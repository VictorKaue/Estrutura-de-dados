#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    Queue *queue = createQueue();
    int option, value;
    do{
        printf("\n--- Linked List Menu ---\n");
        printf("1 - Enque\n");
        printf("2 - Deque\n");
        printf("3 - Show List\n");
        printf("4 - exit\n");
        printf("Choose a option: ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                showQueue(queue);
                break;
            case 4:
                printf("Closing the program...");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != 4);
    printf("Closed successfully!\n");
    freeQueue(queue);

    return 0;   
}