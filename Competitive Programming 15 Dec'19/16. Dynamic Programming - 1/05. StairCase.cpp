#include<iostream>
using namespace std;

long dp[71]={0};
long staircase(int n){
    if(n<0) return 0;
    if(n==1||n==0) return 1;
    if(dp[n]!=0) return dp[n];
    long k= staircase(n-1)+staircase(n-2)+staircase(n-3);
    dp[n]=k;
    return k;
}
int main(){
    int n;
    cin >> n;
    cout << staircase(n) << endl;
}

/*
StairCase Problem
Send Feedback
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7
*/