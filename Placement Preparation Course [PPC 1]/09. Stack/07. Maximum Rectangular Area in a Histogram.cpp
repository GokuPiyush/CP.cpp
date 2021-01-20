/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.
*/


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array
long getMaxArea(long long arr[], int n){
    
    // Your code here
    stack<int> s;
    long ans = 0;
    
    for(int i=0; i<n;){
        if(s.empty() || arr[s.top()]<=arr[i]){
            s.push(i++);
            continue;
        }
        while(arr[s.top()]>arr[i]){
            int tp = s.top();
            s.pop();
            long area = (long)arr[tp]*(s.empty()? i: i-s.top()-1);
            ans = max(ans, area);
            if(s.empty()) break;
        }
    }
    while(!s.empty()){
        int tp = s.top();
        s.pop();
        long area = (long)arr[tp]*(s.empty()? n: n-s.top()-1);
        ans = max(ans, area);
    }
    return ans;
}

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends