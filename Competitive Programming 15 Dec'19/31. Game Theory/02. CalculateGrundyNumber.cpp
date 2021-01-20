#include<bits/stdc++.h>
using namespace std;

int mex(int a, int b, int c){
    for(int i=0; i<=max(a, max(b, c))+1; i++){
        if(i!= a && i!= b && i!= c){
            return i;
		}
    }
}
int grundy(int n, int *dp){
    if(n == 0){
        return 0;
    }
    if(dp[n]!= -1){
        return dp[n];
    }
    dp[n] = mex(grundy(n/2, dp), grundy(n/3, dp), grundy(n/6, dp));
    return dp[n];
}
int main() {

	int n;
    cin>> n;
    int dp[n+1];
    memset(dp, -1, sizeof dp);
    cout<< grundy(n, dp)<< endl;
}

/*
Calculate Grundy Number
Send Feedback
Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?
Input Format
An Integer 'n'
Output Format
Grundy Number(n)
Sample Input 1 -
10
Sample Output 1-
0
*/