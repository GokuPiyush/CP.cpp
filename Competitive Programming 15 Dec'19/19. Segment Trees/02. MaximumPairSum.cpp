#include<bits/stdc++.h>
using namespace std;

int* MAX(int *a, int *b){
    if(*a>=*b) return a;
    else return b;
}
pair<int, int> maxTwo(pair<int, int> p1, pair<int, int> p2){
    pair<int, int> p;
    int *a = &p1.first, *b = &p1.second, *c = &p2.first, *d = &p2.second;
    p.first = *MAX(a, MAX(b, MAX(c, d)));
    *MAX(a, MAX(b, MAX(c, d))) = INT_MIN;
    p.second = *MAX(a, MAX(b, MAX(c, d)));
    return p;
}
void constructST(pair<int, int> st[], int ar[], int start, int end, int node){
    if(start == end){
        st[node] = make_pair(ar[start], INT_MIN);
        return;
    }
    int mid = (start+end)/2;
    constructST(st, ar, start, mid, 2*node);
    constructST(st, ar, mid+1, end, 2*node+1);

    st[node] = maxTwo(st[2*node], st[2*node+1]);
}
void update(pair<int, int> st[], int ar[], int start, int end, int node, int indx, int value){
    if(start == end){
        if(start == indx)
            ar[start] = value, st[node] = make_pair(ar[start], INT_MIN);
        return;
    }
    int mid = (start+end)/2;
    if(indx<= mid)
        update(st, ar, start, mid, 2*node, indx, value);
    else
        update(st, ar, mid+1, end, 2*node+1, indx, value);

    st[node] = maxTwo(st[2*node], st[2*node+1]);
}
pair<int, int> query(pair<int, int> st[], int start, int end, int node, int left, int right){
    if(start>right || end<left) return make_pair(INT_MIN, INT_MIN);
    if(start>=left && end<=right) return st[node];

    int mid = (start+end)/2;
    return maxTwo(query(st, start, mid, 2*node, left, right), 
                  query(st, mid+1, end, 2*node+1, left, right));
}
int main() {
    int n;
    cin>> n;
    int ar[n];
    for(int i=0; i<n; i++)
        cin>> ar[i];
    int q;
    cin>> q;
    int size = 4*n;
    pair<int, int> st[size];
    constructST(st, ar, 0, n-1, 1);
    /*for(int i=1; i<size; i++)
        cout<< st[i].first<< ' '<< st[i].second<< endl;*/
    while(q--){
        char c; int a, b;
        cin>> c>> a>> b;
        if(c == 'U') update(st, ar, 0, n-1, 1, a-1, b);
        if(c == 'Q'){
            pair<int, int> p = query(st, 0, n-1, 1, a-1, b-1);
            cout<< p.first+ p.second<< endl;
        }
    }
}

/*
Maximum Pair Sum
Send Feedback
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
*/