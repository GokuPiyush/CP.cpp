#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, int l1, string s2, int l2, int *dp[]){
    if(l1 == 0 || l2 == 0)
        return 0;
    if(dp[l1][l2] != -1) return dp[l1][l2];
    int ans;
    if(s1[0] == s2[0]){
        ans =  1+lcs(s1.substr(1,l1-1), l1-1, s2.substr(1,l2-1), l2-1, dp);
    }else{
        int opt1 = lcs(s1.substr(1,l1-1), l1-1, s2, l2, dp);
        int opt2 = lcs(s1, l1, s2.substr(1,l2-1), l2-1, dp);
        ans =  max(opt1,opt2);
    }
    dp[l1][l2] = ans;
    return ans;
}
int lcsI(string s1, string s2){
    int n1 = s1.length(), n2 = s2.length();
    
    int dp[n1+1][n2+1];
    for(int i=0; i<n1+1; i++) dp[i][0] = 0;
    for(int i=0; i<n2+1; i++) dp[0][i] = 0;
    
    for(int i=1; i<n1+1; i++){
        for(int j=1; j<n2+1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n1][n2];
}

int main(){
    string st1 = "jagya", st2 = "anandi";
    //cin>> st1>> st2;
    int n1 = st1.length(), n2 = st2.length();

    int *dp[n1+1];
    for(int i=0; i<n1+1; i++)
        dp[i] = new int[n2+1];
    for(int i=0; i<n1+1; i++)
        for(int j=0; j<n2+1; j++)
            dp[i][j] = -1;
    
    cout<< lcs(st1, n1, st2, n2, dp)<< endl;
}

/*
LCS - Problem
Send Feedback
Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to n. E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
Input Format :
Line 1 : String S1
Line 2 : String s2
Output Format :
Line 1 : Length of lcs
Sample Input :
adebc
dcadb
Sample Output :
3
*/