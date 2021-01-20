/*
Given an integer N. Find the number of digits that appear in its factorial. 
Factorial is defined as, factorial(n) = 1*2*3*4……..*N and factorial(0) = 1.
*/


//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


//User function Template for C++

//You need to complete this function
int digitsInFactorial(int N)
{
    //Your code here
    double a = 0;
    for(int i=1; i<=N; i++){
        a += log10(i);
    }
    return int(a) + 1;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<digitsInFactorial(N)<<endl;
    }
    return 0;
}
  // } Driver Code Ends