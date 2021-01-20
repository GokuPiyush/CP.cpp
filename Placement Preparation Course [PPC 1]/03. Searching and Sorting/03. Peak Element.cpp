/*
A peak element in an array is the one that is not smaller than its neighbours.
Given an array of size N, find the index of any one of its peak elements.
*/


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
int bs(int *arr, int n, int l, int r){
    if(l>r) return -1;
    
    int mid = (l+r)/2;
    if(mid == 0){
        if(arr[mid]>=arr[mid+1]) return mid;
        else return bs(arr, n, mid+1, r);
    }
    if(mid == n-1){
        if(arr[mid]>=arr[mid-1]) return mid;
        else return bs(arr, n, l, mid-1);
    }
    if(arr[mid]< arr[mid-1]) return bs(arr, n, l, mid-1);
    if(arr[mid]< arr[mid+1]) return bs(arr, n, mid+1, r);
    return mid;
}
int peakElement(int arr[], int n)
{
   // Your code here
   return bs(arr, n, 0, n-1);
}

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}

	return 0;
}  // } Driver Code Ends