/*
Given a binary matrix. Find the maximum area of a rectangle formed only of 1s in the given matrix.
*/


#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int helper(int *arr, int n){
    
    stack<int> s;
    int ans = 0;
    
    for(int i=0; i<n;){
        if(s.empty() || arr[s.top()]<=arr[i]){
            s.push(i++);
            continue;
        }
        while(arr[s.top()]>arr[i]){
            int tp = s.top();
            s.pop();
            int area = arr[tp]*(s.empty()? i: i-s.top()-1);
            ans = max(ans, area);
            if(s.empty()) break;
        }
    }
    while(!s.empty()){
        int tp = s.top();
        s.pop();
        int area = (long)arr[tp]*(s.empty()? n: n-s.top()-1);
        ans = max(ans, area);
    }
    return ans;
}
int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    int ans = helper(M[0], m);
    
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(M[i][j]){
                M[i][j] += M[i-1][j];
            }
        }
        ans = max(ans, helper(M[i], m));
    }
    return ans;
}
