#include <bits/stdc++.h>
using namespace std;

int kadenesAlgorithm(int ar[], int n){
    int bestSum = INT_MIN, sum = 0;
    for(int i=0; i<n; i++){
        sum += ar[i];
        if(bestSum < sum) bestSum = sum;
        if(sum < 0) sum = 0;
    }
    return bestSum;
}
int largestSumRectangle(int *mat[], int n, int m){
    int bestSum = INT_MIN;
    for(int i=0; i<m; i++){
        int sum[n];
        memset(sum, 0, sizeof sum);
        for(int j=i; j<m; j++){
            for(int k=0; k<n; k++){
                sum[k] += mat[k][j];
            }
            int currentSum = kadenesAlgorithm(sum, n);
            if(currentSum > bestSum) bestSum = currentSum;
        }
    }
    return bestSum;
}
int main(){
    int n, m;
    cin>> n>> m;
    int *mat[n];
    for(int i=0; i<n; i++)
        mat[i] = new int[m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>> mat[i][j];
    cout<< largestSumRectangle(mat, n, m);
    return 0;
}

/*
Maximum Sum Rectangle
Send Feedback
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/