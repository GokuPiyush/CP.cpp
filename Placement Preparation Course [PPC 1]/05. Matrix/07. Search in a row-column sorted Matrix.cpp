/*
Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x. Find whether element x is present in the matrix or not.
*/


#include<bits/stdc++.h> 
using namespace std;
bool search(vector<vector<int> > matrix, int n, int m, int x) ;
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;

        if (search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 

// } Driver Code Ends




bool search(vector<vector<int> > matrix, int n, int m, int x) 
{
    // code here
    int r=0, c=m-1;
    while(r<n && c<m){
        if(matrix[r][c]>x){
            c--;
            continue;
        }
        if(matrix[r][c]<x){
            r++;
            continue;
        }
        else return true;
    }
    return false;
}