/*
Given a Directed Graph with V vertices and E edges, Find the number of strongly connected components in the graph.
*/


#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/
void dfs(vector<int> *adj, vector<bool>& visited, stack<int>& s, int src){
    visited[src] = true;
    for(auto it=adj[src].begin(); it!=adj[src].end(); it++){
        if(!visited[*it]){
            dfs(adj, visited, s, *it);
        }
    }
    s.push(src);
}
void transpose(vector<int> *adj, int V, vector<int> *adjT){
    for(int i=0; i<V; i++){
        for(auto it=adj[i].begin(); it!=adj[i].end(); it++){
            adjT[*it].push_back(i);
        }
    }
}
void dfs2(vector<int> *adj, vector<bool>& visited, int src=0){
    visited[src] = true;
    for(auto it=adj[src].begin(); it!=adj[src].end(); it++){
        if(!visited[*it]){
            dfs2(adj, visited, *it);
        }
    }
}
int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    int ans = 0;
    stack<int> s;
    vector<bool> visited(V, false);
    for(int i=0; i<V; i++){
        if(!visited[i]){
            dfs(adj, visited, s, i);
        }
    }
    vector<int> *adjT = new vector<int>[V];
    transpose(adj, V, adjT);
    visited.assign(V, false);
    while(!s.empty()){
        int src = s.top();
        s.pop();
        if(!visited[src]){
            dfs2(adjT, visited, src);
            ans++;
        }
    }
    return ans;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
  // } Driver Code Ends