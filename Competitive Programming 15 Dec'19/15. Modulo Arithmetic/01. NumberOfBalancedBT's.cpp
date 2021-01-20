#include <iostream>
#include <cmath>
//#include "Solution.h"
using namespace std;
#define M 1000000007

int balancedBTs(int h) {
    if(h<=1) return 1;
    long long int x = balancedBTs(h-1)%M;
    long long int y = balancedBTs(h-2)%M;
    return ((x*x)%M+2*(x*y)%M)%M;
}

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}

/*
Number Of Balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/