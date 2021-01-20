/*
You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
*/


class Solution {
public:
    int forwardPath(vector<vector<int>> grid, vector<vector<int>>& dp, int i=0, int j=0){
        int n=grid.size();
        if(i>=n || j>=n) return INT_MIN;
        if(i==n-1 && j==n-1){
            return dp[i][j] = grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(grid[i][j]==-1) return dp[i][j]=INT_MIN;
        return dp[i][j] = grid[i][j] + 
            max(forwardPath(grid, dp, i+1, j), forwardPath(grid, dp, i, j+1));
    }
    int reversePath(vector<vector<int>> grid, vector<vector<int>>& dp, int i=0, int j=0){
        if(i<0 || j<0) return INT_MIN;
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(grid[i][j]==-1) return dp[i][j]=INT_MIN;
        return dp[i][j] = grid[i][j] + 
            max(reversePath(grid, dp, i-1, j), reversePath(grid, dp, i, j-1));
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp1(n, vector<int>(n, -1)), dp2(n, vector<int>(n, -1));
        int inc = grid[0][0];
        int ans1=forwardPath(grid, dp1);
        int i=0,j=0;
        while(true){
            if(i==n-1 && j==n-1){
                grid[i][j] = 0;
                break;
            }
            if(i+1<n && j+1<n && (dp1[i+1][j]>=0 || dp1[i][j+1]>=0)){
                if(dp1[i+1][j] > dp1[i][j+1]){
                    grid[i++][j] = 0;
                }else{
                    grid[i][j++] = 0;
                }
            }else if(i==n-1 && dp1[i][j+1]>=0){
                grid[i][j++] = 0;
            }else if(j==n-1 && dp1[i+1][j]>=0){
                grid[i++][j] = 0;
            }else
                return 0;
        }
        int ans2=reversePath(grid, dp2, n-1, n-1);
        cout<< ans1<< ' '<< ans2;
        return ans1 + ans2 + inc;
    }
};