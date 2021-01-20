/*
Given two sorted arrays of sizes N and M respectively. The task is to find the median of the two arrays when they get merged.
*/


//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int findMedian(int *, int , int *, int);

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    
	    if(n < m)
	        cout << findMedian(arr, n, brr, m) << endl;
	   else
	        cout << findMedian(brr, m, arr, n) << endl;
	    
	}

}// } Driver Code Ends


//User function template for C++

// arr : given array with size n 
// brr : given array with size m
int findMedian(int arr[], int n, int brr[], int m){
    // code here
    int i, j, *a = new int[n+m]{}, count =0;
    for(i=0, j=0; i<n && j<m;)
        if(arr[i]<brr[j]) a[count++] = arr[i++];
        else a[count++] = brr[j++];
    while(j<m) a[count++] = brr[j++];
    while(i<n) a[count++] = arr[i++];
    return (n+m)%2==0? (a[(n+m)/2]+a[(n+m)/2-1])/2: a[(n+m)/2];
}