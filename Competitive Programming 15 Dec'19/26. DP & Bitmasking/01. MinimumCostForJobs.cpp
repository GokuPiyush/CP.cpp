#include<bits/stdc++.h>
using namespace std;

const int MAX = 15;
int minCost(int cost[MAX][MAX], int n, int p, int mask, int *dp){
	if(p == n){
		return 0;
	}
	if(dp[mask] != -1){
		return dp[mask];
	}
	int minimum = INT_MAX;
	for(int i=0; i<n; i++){
		if(!(mask & (1<<i))){
			int ans = minCost(cost, n, p+1, mask|(1<<i), dp) + cost[p][i];
			minimum = min(minimum, ans);
		}
	}
	dp[mask] = minimum;
	return minimum;
}
main(){
	int n = 4;
	int cost[MAX][MAX] = {{10,2,6,5},
						  {1,15,12,8},
						  {7,8,9,3},
						  {15,13,4,10}};
	int *dp = new int[1<<n];
	for(int i=0; i<(1<<n); i++){
		dp[i] = -1;
	}
	cout<< minCost(cost, n, 0, 0, dp)<< endl;
}