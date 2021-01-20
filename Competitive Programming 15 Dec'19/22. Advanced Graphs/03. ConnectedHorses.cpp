#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

void dfs(int** edge, bool** visited, int n, int m, int* dx, int* dy, int o, int r, int c, int& count){
    visited[r][c] = true;
    count++;
    for(int i=0; i<o; i++){
        int nr = r+dx[i], nc = c+dy[i];
        if(nr>=0 && nc>=0 && nr<n && nc<m && edge[nr][nc] && !visited[nr][nc]){
            dfs(edge, visited, n, m, dx, dy, o, nr, nc, count);
        }
    }
}
long long int fact(int n){
    long long int ans = 1;
    for(int i=1; i<=n; i++){
        ans = (ans*i)%mod;
    }
    return ans;
}
int main()
{
	int t;
    cin>> t;
    while(t--){
        int n, m, q;
        cin>> n>> m>> q;
        int** board = new int*[n];
        for(int i=0; i<n; i++){
            board[i] = new int[m];
            for(int j=0; j<m; j++){
                board[i][j] = 0;
			}
        }
        for(int i=0; i<q; i++){
            int a, b;
            cin>> a>> b;
            board[a-1][b-1] = 1;
        }
        bool** visited = new bool*[n];
        for(int i=0; i<n; i++){
            visited[i] = new bool[m];
            for(int j=0; j<m; j++){
                visited[i][j] = false;
			}
        }
        int dx[8] = {1, -1, 1, -1, 2, 2, -2, -2}, dy[8] = {2, 2, -2, -2, 1, -1, 1, -1};
        
        long long ans = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] && !visited[i][j]){
                    int count = 0;
                    dfs(board, visited, n, m, dx, dy, 8, i, j, count);
                    ans = (ans * fact(count)) %mod;
                }
            }
        }
        cout<< ans<< endl;
    }
	return 0;
}

/*
Connected horses
Send Feedback
You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7
Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2
*/