#include<iostream>
using namespace std;


int helper(int denoms[], int n, int value, int *dp[]){
    if(n == 0) return 0;
    if(value < 0) return 0;
    if(value == 0) return 1;
    if(dp[value][n]!=-1) return dp[value][n];
    dp[value][n] =  helper(denoms+1, n-1, value, dp)+ helper(denoms, n, value-denoms[0], dp);
    return dp[value][n];
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int *dp[value+1];
    for(int i=0; i<value+1; i++){
        dp[i] = new int[numDenominations+1];
        for(int j=0; j<numDenominations+1; j++)
            dp[i][j] = -1;
    }
    return helper(denominations, numDenominations, value, dp);
}

int main(){
    int numDenominations;
    cin >> numDenominations;
    int* denominations = new int[numDenominations];
    for(int i = 0; i < numDenominations; i++){
        cin >> denominations[i];
    }
    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);
}

/*
Coin Change Problem
Send Feedback
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
*/