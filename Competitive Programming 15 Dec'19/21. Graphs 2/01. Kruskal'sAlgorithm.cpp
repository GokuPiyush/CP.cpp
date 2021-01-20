#include <bits/stdc++.h>
using namespace std;

struct edge{int v1, v2, wt;};
bool comp(edge e1, edge e2){ return e1.wt<e2.wt;}

bool unionFind(edge e, int parent[], int V){
    if(parent[e.v1] != parent[e.v2]){
        int tmp = parent[e.v2];
        for(int i=0; i<V; i++)
            if(parent[i] == tmp)
                parent[i] = parent[e.v1];
        return true;
    }else
        return false;
}
void kruskal(edge adjEdge[], int E, int V, edge output[]){
    sort(adjEdge, adjEdge+E, comp);
    int parent[V];
    for(int i=0; i<V; i++)
        parent[i] = i;
    
    int count = 0;
    while(count<V-1){
        for(int i=0; i<E; i++){
            if(unionFind(adjEdge[i], parent, V))
                output[count++] = adjEdge[i];
        }
    }
}
int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    edge adjEdge[E];
    for(int i=0; i<E; i++)
        cin>> adjEdge[i].v1>> adjEdge[i].v2>> adjEdge[i].wt;
    
    edge output[V-1];
    kruskal(adjEdge, E, V, output);
    for(int i=0; i<V-1; i++){
        if(output[i].v1<output[i].v2)
            cout<< output[i].v1<< ' '<< output[i].v2<< ' '<< output[i].wt<< endl;
        else
            cout<< output[i].v2<< ' '<< output[i].v1<< ' '<< output[i].wt<< endl;
    }
  return 0;
}

/*
Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
1 2 1
0 1 3
0 3 5
*/