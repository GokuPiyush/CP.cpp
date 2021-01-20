#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int a[], int n, int k, int **dp){
    if(k == 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    bool ans;
    if(a[n-1]<=k){
        bool opt1 = subsetSum(a, n-1, k-a[n-1], dp);
        bool opt2 = subsetSum(a, n-1, k, dp);
        ans = opt1 | opt2;
    }else{
        ans = subsetSum(a, n-1, k, dp);
    }
    dp[n][k] = ans;
    return ans;
}
int main()
{
    int n;
    cin>> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    int k;
    cin>> k;
    
    int **dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[k+1];
        for(int j=0; j<k+1; j++){
            dp[i][j] = -1;
        }
    }
    subsetSum(a, n, k, dp)?cout<< "Yes"<< endl:cout<< "No"<< endl;
    return 0;
}

/*
Subset Sum - Problem
Send Feedback
Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.

Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes
*/