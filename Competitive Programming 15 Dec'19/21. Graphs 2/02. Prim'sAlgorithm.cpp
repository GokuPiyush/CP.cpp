#include <bits/stdc++.h>
using namespace std;

void prim(int *adjMat[], int V){
    int src = 0;
    bool vis[V];
    int dist[V];
    for(int i=0; i<V; i++)
        vis[i] = false, dist[i] = INT_MAX;
    dist[src] = 0;
    int prnt[V]; prnt[src] = -1;
    
    while(true){
        int ver =-1;
        for(int i=0; i<V; i++){
            if(!vis[i] && (ver == -1 || dist[ver]>dist[i])){
                    ver = i;
            }
        }
        vis[ver] = true;

        for(int i=0; i<V; i++){
            if(!vis[i] && adjMat[ver][i]){
                if(dist[i]>adjMat[ver][i])
                    dist[i] = adjMat[ver][i], prnt[i] = ver;
            }
        }

        bool flag = true;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                flag = false;
                break;
            }
        }
        if(flag)
            break;
    }
    for(int i=1; i<V; i++){
        if(i<prnt[i])
            cout<< i<< ' '<< prnt[i]<< ' '<< dist[i]<< endl;
        else
            cout<< prnt[i]<< ' '<< i<< ' '<< dist[i]<< endl;
    }
}
int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    int *adjMatrix[V];
    for(int i=0; i<V; i++){
        adjMatrix[i] = new int[V];
        for(int j=0; j<V; j++)
            adjMatrix[i][j] = 0;
    }
    for(int i=0; i<E; i++){
        int v1, v2, wt;
        cin>> v1>> v2>> wt;
        adjMatrix[v1][v2] = adjMatrix[v2][v1] = wt;
    }
    prim(adjMatrix, V);
  return 0;
}

/*
Prim's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5
*/