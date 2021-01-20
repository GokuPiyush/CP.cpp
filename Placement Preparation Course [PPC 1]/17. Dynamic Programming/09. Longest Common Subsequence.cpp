/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.
*/


#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

int util(int x, int y, string s1, string s2, int** dp){
    if(x==0||y==0){
        return 0;
    }
    if(dp[x][y] != -1) return dp[x][y];
    if(s1[x-1] == s2[y-1]){
        return dp[x][y] = 1+util(x-1, y-1, s1.substr(0,x-1), s2.substr(0,y-1), dp);
    }
    return dp[x][y] = max(util(x-1, y, s1.substr(0,x-1), s2, dp),
                        util(x, y-1, s1, s2.substr(0, y-1), dp));
}
int lcs(int x, int y, string s1, string s2){
    
    // your code here
    int **dp = new int*[x+1];
    for(int i=0; i<x+1; i++){
        dp[i] = new int[y+1];
        for(int j=0; j<y+1; j++){
            dp[i][j] = -1;
        }
    }
    return util(x, y, s1, s2, dp);
}
