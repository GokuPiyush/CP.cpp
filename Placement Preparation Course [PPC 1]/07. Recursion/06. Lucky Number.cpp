/*
Lucky numbers are subset of integers. Rather than going into much theory, let us see the process of arriving at lucky numbers,
Take the set of integers
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,……
First, delete every second number, we get following reduced set.
1, 3, 5, 7, 9, 11, 13, 15, 17, 19,…………
Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….
Continue this process indefinitely……
Any number that does NOT get deleted due to above process is called “lucky”.
*/


//Initial Template for C++


#include <bits/stdc++.h>
#define ll long long 
using namespace std;



 // } Driver Code Ends


//User-function template for C++

// Complete the function
// n: Input n
// counter: variable has already been declared in driver code and initialized as 2
// Return True if the given number is a lucky number else return False

bool isLucky(int n, int &counter) {
    // add code here
    if(n%counter == 0) return false;
    if(n<counter) return true;
    return isLucky(n-n/counter++, counter);
}

// { Driver Code Starts.

/*Driver function to test above function*/
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin>>n;
        int counter = 2;
        if(isLucky(n, counter))
            cout<<"1\n";
        else
            cout<<"0\n";
    }
    return 0;
}  // } Driver Code Ends