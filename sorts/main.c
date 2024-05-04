#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/// @brief Buble sort. Complexity O(n^2), Adaptive(Yes), Stable(Yes)
/// @param A Array
/// @param n Array size
void Buble(int A[], int n)
{
    int i, j;
    int flag;

    for(i = 0; i < n-1; i++)
    {
        flag = 0;
        for(j = 0; j < n -i - 1; j++)
        {
            if(A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(0 == flag)
            break;
    }
}

void Insertion(int A[], int n)
{
    int i, j, x;

    for(i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while(j > -1 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void Selection(int A[], int n)
{
    int i, j, k;
    
    for(i = 0; i < n-1; i++)
    {
        for(j=k=i; j < n; j++)
        {
            if(A[j] < A[k])
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}

int Partition(int A[], int l, int h)
{
    // pivot finding line, if middle pivot want to be used, than middle element can be swapped with the first element..
    int pivot = A[l];
    int i = l;
    int j = h;
    do
    {
        do {i++;} while (i < h && A[i] <= pivot);// TODO
        do {j--;} while (A[j] > pivot); // > is used this side because we want for j to stop at pivot index in the worst case.
        if(i < j)
            swap(&A[i], &A[j]);
        
    } while (i < j);
    swap(&A[j], &A[l]);
    return j;
}

void QuickSort(int A[], int n)
{
    if(1 == n)
        return;
    int nextPart = 
    Partition(A, 0, n);
    if(0 == nextPart)
        QuickSort(A+1, n-1);
    else if(n-1 == nextPart)
    {
        QuickSort(A, n-1);
    }
    else
    {
        QuickSort(A, nextPart);
        QuickSort(A + nextPart + 1, n - nextPart - 1);
    }
}


int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n=sizeof(A)/ sizeof(int);
    //int A[] = {3, 1, 2, 4}, n=sizeof(A)/ sizeof(int);
    QuickSort(A, n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}