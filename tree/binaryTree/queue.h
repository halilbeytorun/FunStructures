
#ifndef queue_h
#define queue_h
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

// rear will be pointing to into element while front will be pointing empty space
// empty condition: rear == front
// full condition: (rear+1)%size == front   // one empty space is there in full state
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void createQueue(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **) malloc(size * sizeof(struct Node*));
}

void enqueue(struct Queue *q, struct Node* x)
{
    if((q->rear+1)%q->size  == q->front)
        printf("Queue is Full\n");
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}

struct Node* dequeue(struct Queue *q)
{
    struct Node* x = NULL;

    if(q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front+1)%q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmptyQueue(struct Queue *q)
{
    return q->rear == q->front;
}

#endif
