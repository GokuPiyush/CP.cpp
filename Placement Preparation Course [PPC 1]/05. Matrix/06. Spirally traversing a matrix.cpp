/*
Given a matrix of size R*C. Traverse the matrix in spiral form.
*/


#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends







class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int row=0, col=0, tr=r, tc=c, n=r*c;
        while(row<r && col<c){
            bool flag=true;
            while(col<tc-1){
                flag=false;
                ans.push_back(matrix[row][col++]);
            }
            while(row<tr-1)
                ans.push_back(matrix[row++][col]);
            while(col>=c-tc+1)
                ans.push_back(matrix[row][col--]);
            while(row>=r-tr+1)
                ans.push_back(matrix[row--][col]);
            
            if(flag) ans.push_back(matrix[row][col]);
            row += 1, col+=1;
            tr -= 1, tc -= 1;
        }
        
        vector<int> out(n);
        for(int i=0; i<n; i++){
            out[i] = ans[i];
        }
        return out;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends