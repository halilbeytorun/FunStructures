#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    int height; // needed for calculating balance factor.
    struct Node *rchild;
} *root=NULL;


int NodeHeight(struct Node* p)
{
    int hr, hl;
    hr = p && p->rchild ? p->rchild->height : 0;
    hl = p && p->lchild ? p->lchild->height : 0;
    return hr > hl ? hr+1 : hl+1;
}

int BalanceFactor(struct Node* p)
{
    int hr, hl;
    hr = p && p->rchild ? p->rchild->height : 0;
    hl = p && p->lchild ? p->lchild->height : 0;   

    return hl - hr; 
}

struct Node* LLRotation(struct Node* p)
{
    struct Node* pl = p->lchild;

    p->lchild = pl->rchild;
    pl->rchild = p;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;  

    return pl;
}

struct Node* LRRotation(struct Node* p)
{
    struct Node *A, *B, *C;
    A = p;
    B = p->lchild;
    C = B->rchild;

    A->lchild = C->rchild;
    B->rchild = C->lchild;
    C->rchild = A;
    C->lchild = B;

    A->height = NodeHeight(A);
    B->height = NodeHeight(B);
    C->height = NodeHeight(C);
    
    if(A == root)
        root = C;
    return C;
}
struct Node* RRRotation(struct Node* p)
{
    struct Node* pr = p->rchild;

    p->rchild = pr->lchild;
    pr->lchild = p;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(root == p)
        root = pr;  

    return pr;
}
struct Node* RLRotation(struct Node* p)
{
    struct Node *A, *B, *C;
    A = p;
    B = p->rchild;
    C = B->lchild;

    A->rchild = C->lchild;
    B->lchild = C->rchild;
    C->lchild = A;
    C->rchild = B;

    A->height = NodeHeight(A);
    B->height = NodeHeight(B);
    C->height = NodeHeight(C);
    
    if(A == root)
        root = C;
    return C;
}

struct Node* RInsert(struct Node* t, int key)
{
    if(NULL == t)   // create the Node here
    {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        t->height = 1;
        return t;
    }
    else
    {
        if(key < t->data)
        {
            t->lchild = RInsert(t->lchild, key);

        }
        else if(key > t->data)
        {
            t->rchild = RInsert(t->rchild, key);
        }
        t->height = NodeHeight(t);
        // Rotation: LL, LR, RR, RL...
        // LL Rotation
        if(BalanceFactor(t) == 2 && BalanceFactor(t->lchild) == 1)
        {
            return LLRotation(t);
        }
        // LR Rotation
        else if(BalanceFactor(t) == 2 && BalanceFactor(t->lchild) == -1)
        {
            return LRRotation(t);
        }
        // RR Rotation
        else if(BalanceFactor(t) == -2 && BalanceFactor(t->lchild) == -1)
        {
            return RRRotation(t);
        }
        // RL Rotation
        else if(BalanceFactor(t) == -2 && BalanceFactor(t->lchild) == 1)
        {
            return RLRotation(t);
        }        


        return t;
    }
}

int Height(struct Node* p)
{
    if(!p)
        return 0;
    int x, y;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x+1 : y+1;
}

struct Node* InPre(struct Node* p)
{
    while(p && p->rchild)
        p = p->rchild;
    return p;
}

struct Node * InSuc(struct Node* p)
{
    while(p && p->lchild)
        p = p->lchild;
    return p;
}
struct Node* Delete(struct Node* p, int key)
{
    if(p == NULL)
    {
        return NULL;
    }
    if(p->rchild == NULL && p->lchild == NULL)
    {
        if(p->data == key)
        {
            if(p == root)
                root = NULL;
            free(p);
            return NULL;
        }
        return p;
    }
    if(p->data < key)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if(p->data > key)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        struct Node *q;
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSuc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    p->height = Height(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) // L1 rotation
    {
        return LLRotation(p);
    }
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) // L -1 rotation
    {
        return LRRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1) 
    {
        return RRRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1) 
    {
        return RLRotation(p);
    }
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0) // L0 rotation
    {
        return LLRotation(p);
    }
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 0) 
    {
        return RRRotation(p);
    }

}

int main()
{
    root = RInsert(root, 50);
    RInsert(root, 10);
    RInsert(root, 20);
    
    return 0;
}