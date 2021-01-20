/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


 // } Driver Code Ends


// Function to return maximum of sum without adjacent elements
ll FindMaxSumUtil(ll arr[], ll n, int* dp){
    if(n<=0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    if(n >= 2){
        return dp[n] = max(arr[n-1]+FindMaxSumUtil(arr, n-2, dp), arr[n-2]+FindMaxSumUtil(arr, n-3, dp));
    }else{
        return dp[n] = arr[n-1];
    }
}
ll FindMaxSum(ll arr[], ll n)
{
    // Your code here
    int *dp = new int[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = -1;
    }
    return FindMaxSumUtil(arr, n, dp);
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;++i)
			cin>>a[i];
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends