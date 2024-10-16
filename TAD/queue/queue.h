#ifndef QUEUE_H
#define QUEUE_H

typedef struct node {
    double data;
    struct node *next;
    struct node *prev;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue *createQueue();
Node *createNode(double new_data);
int isEmpty(Queue *queue);
void enqueue(Queue *queue, double new_data);
void dequeue(Queue *queue);
void showQueue(Queue *queue);
void freeQueue(Queue *queue);

#endif 