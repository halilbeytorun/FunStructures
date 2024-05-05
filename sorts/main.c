#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/// @brief Buble sort. Complexity O(n^2), Adaptive(Yes), Stable(Yes), can use for K-biggest elements
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
/// @brief InsertionSort. Complexity O(n^2), Adaptive(Yes) Stable(Yes), good for linked list implementations
/// @param A Array
/// @param n Array size
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
/// @brief Selection Sort implementation. Complexity O(n^2), Adaptive(No) Stable(No), can use with K-smallest elements, also swapping number is small.
/// @param A 
/// @param n 
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

/// @brief Partitions the given array with using first element as pivot.
/// @param A array
/// @param l start index of partition
/// @param h ending index of partition, this index is not included in the array
/// @return returns the pivot's position.
int Partition(int A[], int l, int h)
{
    // pivot finding line, if middle pivot want to be used, than middle element can be swapped with the first element..
    int pivot = A[l];
    int i = l;
    int j = h;
    do
    {
        do {i++;} while (i < h && A[i] <= pivot);// TODO revisit
        do {j--;} while (A[j] > pivot); // > is used this side because we want for j to stop at pivot index in the worst case.
        if(i < j)
            swap(&A[i], &A[j]);
        
    } while (i < j);
    swap(&A[j], &A[l]);
    return j;
}

/// @brief Quick Sort implementation.Complexity O(n^2) Adaptive(No) Stable(No)
/// @param A Array to be sorted
/// @param n array size
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

/// @brief Merges two sorted arrays inside A
/// @param A the input of two sorted arrays divided by mid element, output of the resulting array
/// @param low the starting index
/// @param mid the middle index dividing two sorted arrays.
/// @param high the ending index (included)
void Merge(int A[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1];  // this works for gcc
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }
    for (int i=low; i<=high; i++){
        A[i] = B[i];
    }
}
/// @brief Iterative Merge sort implementation.
/// @param A 
/// @param n 
void IterativeMergeSort(int A[], int n){
    int p;
    for (p=2; p<=n; p=p*2){
        int i;
        for (i=0; i+p-1<n; i=i+p){
            int low = i;
            int high = i+p-1;
            int mid = (low+high)/2;
            Merge(A, low, mid, high);
        }
        if(n-i>p/2)
        {
            int l = i;
            int h = i+p-1;
            int mid = (l+h)/2;
            Merge(A, l, mid, n-1);
        }
    }
    if (p/2 < n){
        Merge(A, 0, p/2-1, n-1);
    }
}
 
void RecursiveMergeSort(int A[], int l, int h)
{
    if(l < h)
    {
        int mid = (l+h)/2;
        RecursiveMergeSort(A, l, mid);
        RecursiveMergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}

int findMax(int A[], int n)
{
    int max = A[0];
    for(int i = 0; i < n; i++)
    {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

void CountSort(int A[], int n)
{
    int i, j, max, *C;
    max = findMax(A, n);
    C = (int *) malloc(sizeof(int) * (max + 1));
    for(i = 0; i < max+1;i++)
        C[i] = 0;
    

    for(i = 0;i < n; i++)
    {
        C[A[i]]++;
    }
    i =0; j = 0;
    while(j < max+1)
    {
        if(C[j] > 0)
        {
            A[i++] = j;
            C[j]--;
        }
        else
            j++;
    }
}


void ShellSort(int A[],int n)
{
    int gap,i,j,temp;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp)
            {
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;
        }
    }
}


int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, 1}, n=sizeof(A)/ sizeof(int);
    //int A[] = {3, 1, 2, 4}, n=sizeof(A)/ sizeof(int);
    CountSort(A,n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}