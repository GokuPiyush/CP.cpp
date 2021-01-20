#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2, int **dp){
    int n1 = s1.length(), n2 = s2.length();
    if(n1 == 0){
        dp[n1][n2] = n2;
        return n2;
    }
    if(n2 == 0){
        dp[n1][n2] = n1;
        return n1;
    }
    if(dp[n1][n2] !=-1){
        return dp[n1][n2];
    }
    int ans;
    if(s1[0] == s2[0]){
        ans = editDistance(s1.substr(1,n1-1), s2.substr(1,n2-1), dp);
    }else{
        int insert = editDistance(s1, s2.substr(1,n2-1), dp);
        int remove = editDistance(s1.substr(1,n1-1), s2, dp);
        int replace = editDistance(s1.substr(1,n1-1), s2.substr(1,n2-1), dp);
        ans = 1+min(insert, min(remove, replace));
    }
    dp[n1][n2] = ans;
    return ans;
}
int main(){
    string s1 = "asdf", s2 = "asdf";
    // cin>> s1>> s2;
    int n1 = s1.length(), n2 = s2.length();

    int **dp = new int*[n1+1];
    for(int i=0; i<n1+1; i++){
        dp[i] = new int[n2+1];
        for(int j=0; j<n2+1; j++){
            dp[i][j] = -1;
        }
    }
    
    cout<< editDistance(s1, s2, dp)<< endl;
}

/*
Edit Distance - Problem
Send Feedback
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/