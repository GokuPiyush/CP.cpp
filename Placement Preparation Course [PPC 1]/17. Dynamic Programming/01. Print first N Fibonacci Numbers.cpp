/*
Given a number N, find the first N Fibonacci numbers. The first two number of the series are 1 and 1.
*/


//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
vector<long long> printFibb(int);



int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<long long> ans = printFibb(n);
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends


//User function template for C++

// n : given integer value
// print the nth fibb number in the function 
vector<long long> printFibb(int n) {
    //code here
    vector<long long> fib(n);
    fib[0] = fib[1] = 1;
    for(int i=2; i<n; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    return fib;
}