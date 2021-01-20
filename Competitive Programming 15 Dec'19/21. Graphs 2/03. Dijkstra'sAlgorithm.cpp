#include <bits/stdc++.h>
using namespace std;

void dijkstra(int **adjMat, int V, int *dist, bool *vis){
    int node = -1;
    for(int i=0; i<V; i++){
        if(!vis[i] && (node == -1 || dist[i]<dist[node]))
            node = i;
    }
    vis[node] = true;
    for(int i=0; i<V; i++){
        if(adjMat[node][i] && !vis[i] && dist[i]>adjMat[node][i]+dist[node])
            dist[i] = dist[node] + adjMat[node][i];
    }
    
    bool flag = true;
    for(int i=0; i<V; i++){
        if(!vis[i]){
            flag = false;
            break;
        }
    }
    if(flag) return;
    else dijkstra(adjMat, V, dist, vis);
}
int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    int *adjMat[V];
    for(int i=0; i<V; i++){
        adjMat[i] = new int[V];
        for(int j=0; j<V; j++)
            adjMat[i][j] = 0;
    }
    for(int i=0; i<E; i++){
        int v1, v2, wt;
        cin>> v1>> v2>> wt;
        adjMat[v1][v2] = adjMat[v2][v1] = wt;
    }
    bool vis[V];
    int dist[V];
    for(int i=0; i<V; i++)
        dist[i] = INT_MAX, vis[i] = false;
    dist[0] = 0;
    
    dijkstra(adjMat, V, dist, vis);
    for(int i=0; i<V; i++)
        cout<< i<< ' '<< dist[i]<< endl;
  return 0;
}

/*
Dijkstra's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/