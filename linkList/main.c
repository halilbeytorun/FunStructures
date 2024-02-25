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

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;

    if(index < 1 || index > count(p))
        return -1;
    
    if(index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        
        for(int i = 0; i < index-1; i++)
        {
            q = p;
            p=p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }

}


int isSorted(struct Node *p)
{
    int x = INT_MIN;

    while(p)
    {
        if(p->data < x)
            return 0;
        
        x = p->data;
        p = p->next;
    }
    return 1;
}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;
    while(q)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

// reverses the elements, not the pointers..
void Reverse1(struct Node* p)
{
    int *A;
    struct Node *q = p;
    int i = 0;

    A = (int *) malloc(sizeof(int) * count(p));

    while(q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    i--;
    q = p;
    while(q != NULL)
    {
        q->data = A[i];
        i--;
        q = q->next;
    }
    free(A);
}

void Reverse2(struct Node* p)
{
    struct Node* q= NULL, *r = NULL;
    while(p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3(struct Node *q, struct Node *p)
{
    if(p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

int main()
{
    int A[] = {10, 20, 20, 20, 30 ,40, 50};
    create(A, 7);

    Reverse3(NULL, first);
    display(first);

    printf("\n\n");

}

