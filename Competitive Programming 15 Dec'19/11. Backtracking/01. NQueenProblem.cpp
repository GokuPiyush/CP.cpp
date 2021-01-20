#include<bits/stdc++.h>
using namespace std;
//#include "Solution.h"

const int size=10;
int board[size][size];
void initialize(){
    memset(board, 0, sizeof board);
}
bool check(int n, int row, int col){
    for(int i=row-1, j = 1; i>=0 || (col-j>=0 || col+j<n); i--, j++){
        if(board[i][col] == 1) return false;
        if(col+j<n && board[i][col+j] == 1) return false;
        if(col-j>=0 && board[i][col-j] == 1) return false;
    }
    return true;
        
}
void placeNQueens(int n, int row = 0, int col = 0){
    if(row == 0 && col == 0)
        initialize();
    if(row == n){
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cout<< board[i][j]<< ' ';
        cout<< endl;
        return;
    }
    for(int j=0; j<n; j++){
        if(check(n,row,j))
            board[row][j] = 1, placeNQueens(n, row+1), board[row][j] = 0;
    }
}

int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);

}


/*
N-Queen Problem
Send Feedback
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/