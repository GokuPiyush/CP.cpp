/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
*/


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Returns the maximum value that  
// can be put in a knapsack of capacity W
int knapsackUtil(int W, int wt[], int val[], int n, int **dp) {
    if(n == 0 || W == 0){
        return 0;
    }
    if(dp[W][n] != -1){
        return dp[W][n];
    }
    if(W-wt[n-1] >= 0){
        return dp[W][n] = max(val[n-1]+knapsackUtil(W-wt[n-1], wt, val, n-1, dp), knapsackUtil(W, wt, val, n-1, dp));
    }else{
        return dp[W][n] = knapsackUtil(W, wt, val, n-1, dp);
    }
    
}
int knapSack(int W, int wt[], int val[], int n)
{ 
   // Your code here
   int **dp = new int*[W+1];
   for(int i=0; i<W+1; i++){
       dp[i] = new int[n+1];
       for(int j=0; j<n+1; j++){
           dp[i][j] = -1;
       }
   }
   return knapsackUtil(W, wt, val, n, dp);
}





// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        int val[n];
        int wt[n];
        
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends