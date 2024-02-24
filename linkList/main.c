#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node* next;
}*first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node*) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;

    last = first;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node* p)
{
    while(NULL != p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void r_display(struct Node* p)
{
    if(NULL != p)
    {
        printf("%d ", p->data);
        r_display(p->next);
    }
}


int count(struct Node* p)
{
    int l = 0;
    while(p)
    {
        l++;
        p = p->next;
    }
    return l;
}

int Rcount(struct Node* p)
{
    if(NULL != p)
        return Rcount(p->next) + 1;
    else
        return 0;
}

int sum(struct Node* p)
{
    int s = 0;
    while(p)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int Rsum(struct Node* p)
{
    if(p == NULL)
        return 0;
    else
        return Rsum(p->next) + p->data;
}

int Max(struct Node* p)
{
    int max = INT_MIN;

    while(p)
    {
        if(p->data > max)
            max = p->data;
        p=p->next;
    }
    return max;
}

int RMax(struct Node* p)
{
    if(p == NULL)
        return INT_MIN;
    int min;
    min = RMax(p->next);
    return min > p->data ? min : p->data;
}


struct Node* LSearch(struct Node* p, int key)
{
    struct Node* q;

    while(p)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p=p->next;
    }
    return NULL;
}

struct Node * RSearch(struct Node* p, int key)
{
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return RSearch(p->next, key);
}

void Insert(struct Node* p, int index, int x)
{
    if(index < 0 || index > count(p))
        return;
    
    struct Node* t;

    t = (struct Node*) malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        int i;
        for(i=0; i < index-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void SortedInsert(struct Node* p, int x)
{
    struct Node* t, *q = NULL;
    t = (struct Node*) malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if(first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)  // this part is important..
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    //Insert(first, 0, 10);
    //Insert(first, 1, 20);
    //Insert(first, 2, 30);
    //Insert(first, 0, 3);
    int A[] = {10, 20 , 30 ,40, 50};
    //create(A, 5);

    SortedInsert(first, 55);
    SortedInsert(first, 55);

    display(first);
    printf("\n\n");

}

