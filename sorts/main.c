#include <stdio.h>
#include <stdlib.h>

void swap(int * x, int *y)
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

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n=10;
    Insertion(A, 10);
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}