#include <stdio.h>
#include <stdlib.h>

// Queue will be used for binary tree creation, it is needed for level by level creation.
#include "queue.h"
#include "stack.h"

struct Node *root = NULL;

void createTree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    printf("Enter root value ");
    scanf("%d", &x);
    root = (struct Node*) malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while(!isEmpty(&q))
    {
        p = dequeue(&q);
        printf("enter left child of %d ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node*) malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("enter right child of %d ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node*) malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }

}

void inOrder(struct Node* p)
{
    if(p)
    {
        inOrder(p->lchild);
        printf("%d ", p->data);
        inOrder(p->rchild);
    }
}


void postOrder(struct Node* p)
{
    if(p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ", p->data);
    }
}


void preOrder(struct Node* p)
{
    if(p)
    {
        printf("%d ", p->data);
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void IPreOrder(struct Node* p)
{
    struct Stack stk;
    StackCreate(&stk, 100);

    while(p || !isEmptyStack(&stk))
    {
        if(p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}


void IInOrder(struct Node* p)
{
    struct Stack stk;
    StackCreate(&stk, 100);

    while(p || !isEmptyStack(&stk))
    {
        if(p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}



int main()
{
    createTree();
    printf("\n In Order ");
    IInOrder(root);
}