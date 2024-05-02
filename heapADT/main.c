#include <stdio.h>
#include <stdlib.h>


// Helper function to calculate the height of the tree
int height(int n) {
    int h = 0;
    while ((1 << h) <= n)
        h++;
    return h - 1;
}

// Helper function to print spaces
void printSpaces(int n) {
    for (int i = 0; i < n; i++)
        printf(" ");
}

// Function to print max heap tree
void printMaxHeapTree(int A[], int n) {
    int h = height(n);
    int max_nodes = 1 << h;
    int nodes = 1;

    int i = 1;
    while (i <= n) {
        printSpaces((max_nodes - nodes) / 2); // Print leading spaces
        for (int j = 0; j < nodes && i <= n; j++) {
            printf("%d ", A[i++]); // Print nodes
            printSpaces((max_nodes - nodes)); // Print spaces between nodes
        }
        printf("\n");
        nodes *= 2; // Double the number of nodes for next level
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
    for(i = 1; i < n; i++)
        Insert(A, i);
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