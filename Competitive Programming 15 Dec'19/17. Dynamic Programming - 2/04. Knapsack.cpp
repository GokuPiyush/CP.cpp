#include<bits/stdc++.h>
using namespace std;

int helper(int* weights, int* values, int n, int maxWeight, int **dp){
    if(n == 0){
        return 0;
    }
    if(dp[n][maxWeight] != -1){
        return dp[n][maxWeight];
    }
    int ans;
    if(weights[n-1]<=maxWeight){
        int opt1 = values[n-1]+helper(weights, values, n-1, maxWeight-weights[n-1], dp);
        int opt2 = helper(weights, values, n-1, maxWeight, dp);
        ans = max(opt1, opt2);
    }else{
        ans = helper(weights, values, n-1, maxWeight, dp);
    }
    dp[n][maxWeight] = ans;
    return ans;
}
int knapsack(int* weights, int* values, int n, int maxWeight){
    int **dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[maxWeight+1];
        for(int j=0; j<maxWeight+1; j++){
            dp[i][j] = -1;
        }
    }
    return helper(weights, values, n, maxWeight, dp);
}
int knapsackIO(int* weights, int* values, int n, int maxWeight){
    int currRow[maxWeight+1], prevRow[maxWeight+1];
    memset(prevRow, 0, sizeof prevRow);
    for(int i=1; i<n+1; i++){
        currRow[0] = 0;
        for(int j=1; j<maxWeight+1; j++){
            if(j-weights[i-1]>=0){
                currRow[j] = max(values[i-1]+prevRow[j-weights[i-1]], prevRow[j]);
            }else{
                currRow[j] = prevRow[j];
            }
        }
        for(int j=0; j<maxWeight+1; j++){
            prevRow[j] = currRow[j];
        }
    }
    return currRow[maxWeight];
}
int main(){
    int n; 
    cin >> n;
    int* weights = new int[n];
    int* values = new int[n];

    for(int i = 0; i < n; i++){
    cin >> weights[i];
    }

    for(int i = 0; i < n; i++){
    cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsackIO(weights, values, n, maxWeight);
}

/*
Knapsnack - Problem
Send Feedback
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/