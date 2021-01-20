#include <bits/stdc++.h>
using namespace std;

int lis(int ar[], int n){
    int dp[n];
    for(int i=0; i<n; i++) dp[i] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(ar[i]>ar[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return dp[n-1];
}

int main(){
    int n = 7;
    // cin>> n;
    int a[n] = {4, 3, 9, 7, 6, 8, 20};
    /* for(int i=0; i<n; i++)
        cin>> a[i]; */
    cout<< lis(a, n)<< endl;
}