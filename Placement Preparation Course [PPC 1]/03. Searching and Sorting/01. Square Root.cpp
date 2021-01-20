/*
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).
*/


#include<bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x);
  

 // } Driver Code Ends


// Function to find square root
// x: element to find square root
long long int bs(long long int l, long long int r, long long int x){
    if(l>r) return r;
    
    long long int mid = (l+r) / 2;
    if(mid*mid == x) return mid;
    if(mid*mid < x) return bs(mid+1, r, x);
    if(mid*mid > x) return bs(l, mid-1, x);
}
long long int floorSqrt(long long int x) 
{
    // Your code goes here   
    return bs(0, x, x);
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout << floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends