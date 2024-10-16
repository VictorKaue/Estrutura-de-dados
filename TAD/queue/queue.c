#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *createQueue() {
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Error creating queue!\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

Node *createNode(double new_data) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error at createNode!\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

int isEmpty(Queue *queue) {
    if (queue == NULL)
        return 1;  
    return (queue->front == NULL);
}

void enqueue(Queue *queue, double new_data) {
    if (queue == NULL) {
        printf("Queue does not exist!\n");
        return;
    }
    
    Node *new_node = createNode(new_data);

    if (isEmpty(queue)) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        new_node->prev = queue->rear;
        queue->rear = new_node;
    }
    queue->size++;
}

void dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    Node *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front != NULL) {
        queue->front->prev = NULL;
    } else {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;
}

void showQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    Node *temp = queue->front;
    while (temp != NULL) {
        printf("%.2f -> ", temp->data);  
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeQueue(Queue *queue) {
    if (queue == NULL) {
        printf("Queue is already empty or does not exist!\n");
        return;
    }

    Node *temp;
    while (queue->front != NULL) {
        temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }

    free(queue);
}
