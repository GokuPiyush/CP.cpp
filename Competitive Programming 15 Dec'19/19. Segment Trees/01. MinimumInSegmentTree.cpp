#include<bits/stdc++.h>
using namespace std;

void constructST(int st[], int ar[], int start, int end, int node){
    if(start == end){
        st[node] = ar[start];
        return;
    }
    int mid = (start+end)/2;
    constructST(st, ar, start, mid, 2*node);
    constructST(st, ar, mid+1, end, 2*node+1);

    st[node] = min(st[2*node], st[2*node+1]);
}
void update(int st[], int ar[], int start, int end, int node, int indx, int value){
    if(start == end){
        if(start == indx)
            ar[start] = value, st[node] = ar[start];
        return;
    }
    int mid = (start+end)/2;
    if(indx<= mid) update(st, ar, start, mid, 2*node, indx, value);
    else update(st, ar, mid+1, end, 2*node+1, indx, value);

    st[node] = min(st[2*node], st[2*node+1]);
}
int query(int st[], int start, int end, int node, int left, int right){
    if(start>right || end<left) return INT_MAX;
    if(start>=left && end<=right) return st[node];

    int mid = (start+end)/2;
    return min(query(st, start, mid, 2*node, left, right), query(st, mid+1, end, 2*node+1, left, right));
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin>> n>> q;
    int ar[n];
    for(int i=0; i<n; i++)
        cin>> ar[i];
    int size = 4*n, st[size];
    // memset(st, INT_MAX, sizeof st);
    constructST(st, ar, 0, n-1, 1);
    
    while(q--){
        char c; int x, y;
        cin>> c>> x>> y;
        if(c == 'u') update(st, ar, 0, n-1, 1, x-1, y);
        if(c == 'q') cout<< query(st, 0, n-1, 1, x-1, y-1)<< endl;
    }
}

/*
Minimum In SubArray
Send Feedback
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.
Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.
Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].
Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N
Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/