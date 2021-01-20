/*
Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page
*/


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
int util(int n, int k, int** dp){
    if(k <= 1){
        return k;
    }
    if(n == 1){
        return k;
    }
    if(dp[n][k] != -1){
        return dp[n][k];
    }
    int best = INT_MAX;
    for(int i=1; i<=k; i++){
        best = min(best, 1+max(util(n-1, i-1, dp), util(n, k-i, dp)));
    }
    return dp[n][k] = best;
}
int eggDrop(int n, int k) 
{
    // your code here
    int** dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[k+1];
        for(int j=0; j<k+1; j++){
            dp[i][j] = -1;
        }
    }
    return util(n, k, dp);
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;

        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends