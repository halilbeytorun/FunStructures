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
        return father;
    }
    else    // Rotation occurs
    {
        father->lchild = t->rchild;
        t->rchild = father;
        t->color = Black;
        father->color = Red;
        if(father == root)
            root = t;
        return t;
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
        return father;
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

        C->color = Black;
        A->color = Red;
        return C;
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
        return father;
    }
    else
    {
        father->rchild = t->lchild;
        t->lchild = father;
        t->color = Black;
        father->color = Red;
        if(father == root)
            root = t;
        return t;
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
        return father;
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

        C->color = Black;
        A->color = Red;
        return C;
    }
}

// Red Black Tree insertion. The insertion and rotations are done in grandfather part of the recursion function since the root of the rotation and effected parts are startong from there..
// therefore grandfather can change in those cases, so something else needed to be returned. That is the reason.
struct Node* RInsert(struct Node* t, int key)
{
    if(NULL == t)
    {
        t = (struct Node*) malloc(sizeof(struct Node));
        t->lchild = t->rchild = NULL;
        t->data = key;
        t->color = Red;   // Handle root node at main function.
    }
    else
    {
        if(key < t->data)
        {
            t->lchild = RInsert(t->lchild, key);
            if(t->lchild->color == Red && t->lchild->lchild && t->lchild->lchild->color == Red)
            {
                return HandleColorLL(t->lchild, t);
            }
            else if(t->lchild->color == Red && t->lchild->rchild && t->lchild->rchild->color == Red)
            {
                return HandleColorLR(t->lchild, t);
            }
        }
        else if(key > t->data)
        {
            t->rchild = RInsert(t->rchild, key);
            if(t->rchild->color == Red && t->rchild->rchild && t->rchild->rchild->color == Red)
            {
                return HandleColorRR(t->rchild, t);
            }
            else if(t->rchild->color == Red && t->rchild->lchild && t->rchild->lchild->color == Red)
            {
                return HandleColorRL(t->rchild, t);
            }
        }
    }
    return t;
}


int main()
{
    root = RInsert(root, 10);
    root->color = Black;

    RInsert(root, 20);  
    RInsert(root, 30);

    RInsert(root, 50);
    RInsert(root, 40);
    RInsert(root, 60);
    RInsert(root, 70);
    // RInsert(root, 80);

    // RInsert(root, 4);
    // RInsert(root, 8);


    printf("Red-Black Tree:\n");
    printTree(root, 0); // TODO STILL PROBLEMATIC

    return 0;
}