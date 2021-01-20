/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
*/


#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int, int> mp;
    int sum=0, maxLen=0;
    for(int i=0; i<n; i++){
        sum += A[i];
        if(sum == 0){
            maxLen = max(maxLen, i+1);
        }
        if(mp[sum]){
            maxLen = max(maxLen, i+1-mp[sum]);
        }else{
            mp[sum] = i+1;
        }
    }
    return maxLen;
}
