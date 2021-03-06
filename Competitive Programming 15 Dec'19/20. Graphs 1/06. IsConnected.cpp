#include <bits/stdc++.h>
using namespace std;

void isConnected(bool **adjMat, bool *visited, int v, int s=0){
    visited[s] = true;
    // cout<< s<< endl;
    for(int i=0; i<v; i++){
        if(adjMat[s][i] && !visited[i])
            isConnected(adjMat, visited, v, i);
    }
}
int main() {
    int V, E;
    cin >> V >> E;
    bool **adjMat = new bool*[V];
    for(int i=0; i<V; i++){
        adjMat[i] = new bool[V];
        for(int j=0; j<V; j++)
            adjMat[i][j] = false;
    }
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    for(int i=0; i<E; i++){
        int a, b;
        cin>> a>> b;
        adjMat[a][b] = adjMat[b][a] = true;
    }
    
    isConnected(adjMat, visited, V);
    
    string ans = "true";
    for(int i=0; i<V; i++){
        if(!visited[i]){
            ans = "false";
            break;
        }
    }
    cout<< ans<< endl;
  return 0;
}

/*
Code : Is Connected ?
Send Feedback
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
"true" or "false"
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
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/