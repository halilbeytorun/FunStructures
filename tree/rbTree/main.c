#include <stdio.h>
#include <stdlib.h>

enum color
{
    Black,
    Red
};

struct Node
{
    struct Node *lchild;
    int data;
    enum color color; // needed for calcualting rotation   0 Black 1 Red.
    struct Node *rchild;
} *root=NULL;

// TODO: Implement tree printing function.
// TODO: Needs to be tested.


void printTree(struct Node* root, int level) {
    if (root == NULL)
        return;

    // Increase indentation for each level
    level += 5;

    // Print right child first
    printTree(root->rchild, level);

    // Print current node after spaces
    printf("\n");
    for (int i = 5; i < level; i++)
        printf(" ");
    printf("%d(%s)\n", root->data, root->color == Red ? "Red" : "Black");

    // Print left child
    printTree(root->lchild, level);
}



struct Node* HandleColorLL(struct Node* t, struct Node* father)
{
    struct Node* uncle = father->rchild;

    if(uncle && uncle->color == Red)
    {
        uncle->color = Black;
        t->color = Black;
        father->color = father == root ? Black : Red;
        return father->lchild;
    }
    else
    {
        father->lchild = t->rchild;
        t->rchild = father;
        t->color = Black;
        father->color = Red;
        if(father == root)
            root = t;
        return father->lchild;
    }
}

struct Node* HandleColorRL(struct Node* t, struct Node* father)
{
    struct Node* uncle = father->lchild;

    if(uncle && uncle->color == Red)
    {
        uncle->color = Black;
        t->color = Black;
        father->color = father==root ? Black : Red;
        return father->rchild;
    }
    else
    {
        struct Node* A = father;
        struct Node* B = t;
        struct Node* C = t->lchild;

        A->rchild = C->lchild;
        B->lchild = C->rchild;
        C->rchild = B;
        C->lchild = A;
        return father->rchild;
    }
}

struct Node* HandleColorRR(struct Node* t, struct Node* father)
{
    struct Node* uncle = father->lchild;

    if(uncle && uncle->color == Red)
    {
        uncle->color = Black;
        t->color = Black;
        father->color = father == root ? Black : Red;
        return father->rchild;
    }
    else
    {
        father->rchild = t->lchild;
        t->lchild = father;
        t->color = Black;
        father->color = Red;
        if(father == root)
            root = t;
        return father->rchild;
    }
}

struct Node* HandleColorLR(struct Node* t, struct Node* father)
{
    struct Node* uncle = father->rchild;

    if(uncle && uncle->color == Red)
    {
        uncle->color = Black;
        t->color = Black;
        father->color = father==root ? Black : Red;
        return father->lchild;
    }
    else
    {
        struct Node* A = father;
        struct Node* B = t;
        struct Node* C = t->rchild;

        A->lchild = C->rchild;
        B->rchild = C->lchild;
        C->lchild = B;
        C->rchild = A;
        return father->lchild;
    }
}

struct Node* InsideInsert(struct Node* t, struct Node* father, int key)
{
    if(NULL == t)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->lchild = t->rchild = NULL;
        t->data = key;
        t->color = Red;     // child node is always black.
    }
    else
    {
        if(key < t->data)
        {
            t->lchild = InsideInsert(t->lchild, t, key);
            if(t->color == Red && t->lchild && t->lchild->color == Red)
            {
                if(father->lchild == t)
                {
                    return HandleColorLL(t, father);
                }
                else
                {
                    return HandleColorRL(t, father);
                }
            }
            return t;
        }
        else if(key > t->data)
        {
            t->rchild = InsideInsert(t->rchild, t, key);
            if(t->color == Red && t->rchild && t->rchild->color == Red)
            {
                if(father->rchild == t)
                {
                    return HandleColorRR(t, father);
                }
                else
                {
                    return HandleColorLR(t, father);
                }
            }
            return t;              
        }
    }
    return t;
}

struct Node* RInsert(struct Node* t, int key)
{
    if(NULL == t)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->lchild = t->rchild = NULL;
        t->data = key;
        t->color = Black;   // root node is always black.
        root = t;
    }
    else
    {
        if(key < t->data)
        {
            t->lchild = InsideInsert(t->lchild, t, key);    // handling
        }
        else if(key > t->data)
        {
            t->rchild = InsideInsert(t->rchild, t, key);
        }
    }
    return t;
}


int main()
{
    RInsert(root, 10);
    // printf("Red-Black Tree:\n");
    // printTree(root, 0);

    RInsert(root, 20);
    // printf("Red-Black Tree:\n");
    // printTree(root, 0);    
    
    RInsert(root, 30);
    // printf("Red-Black Tree:\n");
    // printTree(root, 0);

    RInsert(root, 40);
    printf("Red-Black Tree:\n");
    printTree(root, 0); // TODO STILL PROBLEMATIC

    RInsert(root, 50);

    // printf("Red-Black Tree:\n");
    // printTree(root, 0);
    
    return 0;
}