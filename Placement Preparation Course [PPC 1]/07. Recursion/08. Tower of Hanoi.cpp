/*
The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs N. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.
Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N. Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc. Refer the provided link to get a better clarity about the puzzle.
*/


#include<bits/stdc++.h>
using namespace std;

long long toh(int n, int from, int to, int aux);

int main() {

    int T;
    cin >> T;
    while (T--) {
        long long moves = 0;
        int N;
        cin >> N;
        moves = toh(N, 1, 3, 2);
        cout << moves << endl;
    }
    return 0;
}



 // } Driver Code Ends


// You need to complete this function

// avoid space at the starting of the string in "move disk....."
long long toh(int N, int from, int to, int aux) {
    // Your code here
    if(N == 0) return 0;
    int ans1 = toh(N-1, from, aux, to);
    printf("move disk %d from rod %d to rod %d\n", N, from, to);
    int ans2 = toh(N-1, aux, to, from);
    return 1+ans1+ans2;
}


// { Driver Code Starts.  // } Driver Code Ends