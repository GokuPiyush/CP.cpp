/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
*/


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

bool isCyclicUtil(vector<int> *adj, int v, bool* visited, int parent=-1){
    visited[v] = true;
    for(auto it=adj[v].begin(); it!=adj[v].end(); it++){
        if(!visited[*it]){
            if(isCyclicUtil(adj, *it, visited, v)){
                return true;
            }
        }else if(parent!= *it){
            return true;
        }
        
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   bool visited[V];
    memset(visited, false, sizeof visited);
    for(int i=0; i<V; i++){
        if(!visited[i]){
            if(isCyclicUtil(g, i, visited)){
                return true;
            }
        }
    }
    return false;
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends