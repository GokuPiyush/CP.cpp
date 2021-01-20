#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    bool adjMat[V][V];
    memset(adjMat, false, sizeof adjMat);
    while(E--){
        int a, b;
        cin>> a>> b;
        adjMat[a][b] = true, adjMat[b][a] = true;
    }
    list<int> q;
    q.push_back(0);
    bool vis[V];
    memset(vis, false, sizeof vis);
    vis[0] = true;
    while(true){
        for(int i=0; i<V; i++){
            if(adjMat[q.front()][i] && !vis[i])
                q.push_back(i), vis[i] = true;
        }
        cout<< q.front()<< ' ';
        q.pop_front();
        // for disconnected graph
        bool flag = true;
        if(q.empty()){
            for(int i=0; i<V; i++){
                if(!vis[i]){
                    flag = false;
                    q.push_back(i), vis[i] = true;
                    break;
                }
            }
            if(flag) break;
        }
    }
    
  return 0;
}

/*
Code : BFS Traversal
Send Feedback
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : 1. Take graph input in the adjacency matrix.
2. Handle for Disconnected Graphs as well
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/