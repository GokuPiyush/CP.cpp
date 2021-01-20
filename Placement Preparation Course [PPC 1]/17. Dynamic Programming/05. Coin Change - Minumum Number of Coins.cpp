/*
You are given an amount denoted by value. You are also given an array of coins. The array contains the denominations of the give coins. You need to find the minimum number of coins to make the change for value using the coins of given denominations. Also, keep in mind that you have infinite supply of the coins.
*/


//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//Complete this function
int minCoins(int coins[], int m, int V) 
{ 
    // table[i] will be storing the minimum number of coins 
    // required for i value.  So table[V] will have result 
    int table[V+1]; 
  
    // Base case (If given value V is 0) 
    table[0] = 0; 
  
    // Initialize all table values as Infinite 
    for (int i=1; i<=V; i++) 
        table[i] = INT_MAX; 
  
    // Compute minimum coins required for all 
    // values from 1 to V 
    for (int i=1; i<=V; i++) 
    { 
        // Go through all coins smaller than i 
        for (int j=0; j<m; j++) 
          if (coins[j] <= i) 
          { 
              int sub_res = table[i-coins[j]]; 
              if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
                  table[i] = sub_res + 1; 
          } 
    } 
    return table[V] == INT_MAX? -1: table[V]; 
} 
long long minimumNumberOfCoinsUtil(int *coins, int n, int value, long long** dp){
    if(value<0 || n==0){
        return INT_MAX;
    }
    if(value == 0){
        return 0;
    }
    if(dp[value][n] != -1){
        return dp[value][n];
    }
    return dp[value][n] = min(1+minimumNumberOfCoinsUtil(coins, n, value-coins[n-1], dp), minimumNumberOfCoinsUtil(coins, n-1, value, dp));
}
long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
{
    // your code here
    long long **dp = new long long*[value+1];
    for(int i=0; i<value+1; i++){
        dp[i] = new long long[numberOfCoins+1];
        for(int j=0; j<numberOfCoins+1; j++){
            dp[i][j] = -1;
        }
    }
    long long ans = minimumNumberOfCoinsUtil(coins, numberOfCoins, value, dp);
    
    for(int i=0; i<value+1; i++){
        delete[] dp[i];
    }
    delete[] dp;
    return ans == INT_MAX? -1: ans;
    
}

// { Driver Code Starts.



int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int value;
	    cin>>value;
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    int answer=minimumNumberOfCoins(coins,numberOfCoins,value);
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends