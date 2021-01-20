/*
Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the BFS traversal of the graph starting from the 0th vertex from left to right according to the graph..
*/


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
vector<int> dfsUtil(vector<int> g[], int N, bool* vis, vector<int>& ans, int s=0){
    vis[s] = true;
    ans.push_back(s);
    for(auto it=g[s].begin(); it!=g[s].end(); it++){
        if(!vis[*it]){
            dfsUtil(g, N, vis, ans, *it);
        }
    }
    return ans;
}
vector <int> dfs(vector<int> g[], int N)
{
    
    // Your code here
    bool vis[N];
    memset(vis, false, sizeof vis);
    vector<int> ans;
    dfsUtil(g, N, vis, ans);
    return ans;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends