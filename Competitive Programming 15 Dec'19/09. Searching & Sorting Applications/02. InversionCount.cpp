#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

void helper(int *arr, int n, int si, int ei, long long &ans){
    if(si>=ei){
        return;
    }
    int mi = (si+ei)/2;
    helper(arr, n, si, mi, ans);
    helper(arr, n, mi+1, ei, ans);
    
    int ref[ei-si+1], li = si, ri = mi+1, i;
    for(i=0; li<=mi && ri<=ei; i++){
        if(arr[li]<=arr[ri]){
            ref[i] = arr[li++];
        }else{
            ref[i] = arr[ri++];
            ans += (mi-li+1);
        }
    }
    for(i; i<ei-si+1; i++){
        ref[i] = li>mi? arr[ri++]: arr[li++];
    }
    for(i=si; i<=ei; i++){
        arr[i] = ref[i-si];
    }
}
long long solve(int A[], int n){
    long long ans = 0ll;
	helper(A, n, 0, n-1, ans);
    return ans;
}

int main(){
    int n, A[MAXN];
    cin>> n;
    for(int i = 0; i < n ; i++){
        cin>> A[i];
    }
    cout<< solve(A,n)<< endl;
}

/*
Inversion Count
Send Feedback
Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4
*/