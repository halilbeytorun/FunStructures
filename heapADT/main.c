#include <stdio.h>
#include <stdlib.h>


void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/// @brief Create a heap data structure from a given random array.
/// @param A Random array
/// @param n The size of the array.
/// @details The idea is to go from leafs to root, while going check every node's child, switch with the biggest child if the child is bigger. 
void Heapify(int A[], int n)
{
    for(int i = n-1; i > 0; i--)
    {
        int j = 2 * i;
        if(j >= n)
            continue;
        else if(j + 1 < n)
        {
            j = (A[j] > A[j + 1] ? j : j+1);
            if(A[i] < A[j])
                swap(&A[i], &A[j]);
        }
        else
        {
            if(A[i] < A[j])
                swap(&A[i], &A[j]);
        }
    }
}


/// @brief Insertion into heap ADT
/// @param A Heap array
/// @param n The index of the first empty place (the element is there also)
void Insert(int A[], int n)
{
    int temp = A[n];
    int i = n;
    while(i > 1 && temp > A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

/// @brief Deletion from heap ADT
/// @param A Heap array
/// @param n The index of the last element of the heap(the deleted element will be put to this index.)
void Delete(int A[], int n)
{
    int deleted_el = A[1];    // Store deleted element
    A[1] = A[n];
    int i = 1;
    int j = 2 * i;
    while(j < n)
    {
        if(j+1 != n && A[j] < A[j+1])
            j = j+1;    // select the bigger child.
        if(A[i] < A[j])
        {
            int localTemp = A[i];
            A[i] = A[j];
            A[j] = localTemp;
            i = j;
            j = 2 * i;  // update j and i
        }
        else
            break;
    }
    A[n] = deleted_el;    // putting the deleted element to the last place.
}



int main()
{
    // Heap creation steps!
    int A[] = {0 /* this index won't be used*/, 10, 20, 30, 25, 5, 40, 35,1,2,3,4};
    int i;
    int n = sizeof(A) / sizeof(int);
    // for(i = 1; i < n; i++)
    //     Insert(A, i);
    Heapify(A, n);
    for(i = n - 1; i >= 1; i--)
    {
        Delete(A, i);
    }
    // Array will be sorted after this.
    for(i = 1; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;

}