/*
Merge Sort is a Divide and Conquer algorithm. It repeatedly divides the array into two halves and combines them in sorted manner. 

Given an array arr[], its starting position l and its ending position r. Merge Sort is achieved using the following algorithm. 

MergeSort(arr[], l,  r)
    If r > l
         1. Find the middle point to divide 
            the array into two halves:  
                 middle m = (l+r)/2
         2. Call mergeSort for first half:   
                 Call mergeSort(arr, l, m)
         3. Call mergeSort for second half:
                 Call mergeSort(arr, m+1, r)
         4. Merge the two halves sorted in 
            step 2 and 3:
                 Call merge(arr, l, m, r)
Implement the merge() function used in MergeSort().
*/


#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r);

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}// } Driver Code Ends


/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
     // Your code here
    int i, j, *a = new int[r-l+1]{}, count =0;
    for(i=l, j=m+1; i<=m && j<=r;)
        if(arr[i]<arr[j]) a[count++] = arr[i++];
        else a[count++] = arr[j++];
    while(j<=r) a[count++] = arr[j++];
    while(i<=m) a[count++] = arr[i++];
    
    count=l;
    for(int i=0; i<r-l+1; i++) arr[count++] = a[i];
}