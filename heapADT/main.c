#include <stdio.h>
#include <stdlib.h>

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


void Delete(int A[], int n)
{
    int deleted_el = A[1];    // Store deleted element
    A[1] = A[n];
    int i = 1;
    int j = 2 * i;
    while(j < n-1)
    {
        if(A[j] < A[j+1])
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
    int A[] = {0 /* this index won't be used*/, 10, 20, 30, 25, 5, 40, 35};
    int i;
    for(i = 1; i < sizeof(A) / sizeof(int); i++)
        Insert(A, i);
    for(i = sizeof(A) / sizeof(int) - 1; i >= 1; i--)
    {
        Delete(A, i);
    }
    // Array will be sorted after this.
    for(i = 1; i < sizeof(A) / sizeof(int); i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;

}