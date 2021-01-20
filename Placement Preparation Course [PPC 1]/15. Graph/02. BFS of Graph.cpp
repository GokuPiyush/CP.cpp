/*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph.
*/


#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    vector<int> ans;
    bool visited[N];
    for(int i=0; i<N; i++){
        visited[i] = false;
    }
    int start=0;
    list<int> q;
    visited[start] = true;
    q.push_back(start);
    
    while(!q.empty()){
        start = q.front();
        q.pop_front();
        for(auto it=g[start].begin(); it!=g[start].end(); it++){
            if(!visited[*it]){
                visited[*it] = true;
                q.push_back(*it);
            }
        }
        ans.push_back(start);
    }
    return ans;
    
}