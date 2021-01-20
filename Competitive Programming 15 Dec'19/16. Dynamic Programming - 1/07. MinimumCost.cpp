#include<bits/stdc++.h>
using namespace std;

int minCost(int input[3][3], int si, int sj, int ei, int ej, int dp[3][3]){
    if(si == ei && sj == ej){
        dp[si][sj] = input[ei][ej];
        return input[ei][ej];
    }
    if(si>ei || sj>ej){
        return INT_MAX;
    }
    if(dp[si][sj]!=-1){
        return dp[si][sj];
    }
    int option1 = minCost(input, si, sj+1, ei, ej, dp);
    int option2 = minCost(input, si+1, sj+1, ei, ej, dp);
    int option3 = minCost(input, si+1, sj, ei, ej, dp);
    dp[si][sj] =  input[si][sj] + min(option1, min(option2, option3));
    return dp[si][sj];
}
int main(){
    int input[3][3] = {{4, 3, 2},
                       {1, 8, 3},
                       {1, 1, 8}};
    int dp[3][3];
    memset(dp, -1, sizeof dp);
    cout<< minCost(input, 0, 0, 2, 2, dp);
}