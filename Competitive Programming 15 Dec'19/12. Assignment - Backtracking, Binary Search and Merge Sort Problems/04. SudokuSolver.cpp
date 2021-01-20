#include<iostream>
using namespace std;
//#include "Solution.h"

const int n = 9, rn = 3;

bool check(int board[n][n], int row, int col, int num){
    for(int i=0; i<n; i++)
        if(board[i][col] == num)
            return false;
    for(int i=0; i<n; i++)
        if(board[row][i] == num)
            return false;
    for(int i=rn*(int)(row/rn); i<rn*(int)(row/rn+1); i++)
        for(int j=rn*(int)(col/rn); j<rn*(int)(col/rn+1); j++)
            if(board[i][j] == num)
                return false;
    return true;
}
bool sudokuSolver(int board[n][n]){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(!board[i][j]){
                int k;
                for(k=1; k<n+1; k++){
                    if(check(board, i, j, k)){
                        board[i][j] = k;
                        if(sudokuSolver(board)) return true;
                        board[i][j] = 0;
                    }
                }
                if(k == n+1) return false;
            }
        }
    }
    if(i == n && j == n) return true;
}

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
    for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }       
  }
  if(sudokuSolver(board)){
    cout << "true"; 
  }else{
    cout << "false";    
  }
}


/*
Sudoku Solver
Send Feedback
Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true
*/