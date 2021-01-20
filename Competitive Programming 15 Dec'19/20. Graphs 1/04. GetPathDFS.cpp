#include <bits/stdc++.h>
using namespace std;

list<int> getPathDFS(bool** edge, bool* vis, int V, int v1, int v2){
    if(v1 == v2){
    	list<int> path;
        path.push_back(v1);
        return path;
    }
    vis[v1] = true;
    for(int i=0; i<V; i++){
        if(edge[v1][i] && !vis[i]){
            list<int> path = getPathDFS(edge, vis, V, i, v2);
            if(!path.empty()){
                path.push_back(v1);
                return path;
            }
        }
    }
    return {};
}
int main()
{
  	int V, E, tempX, tempY;
  	cin >> V >> E;
	bool** edges = new bool*[V];
    for(int i=0; i<V; i++){
        edges[i] = new bool[V];
        for(int j=0; j<V; j++){
            edges[i][j] = false;
        }
    }
    while(E--){
        cin>> tempX>> tempY;
        edges[tempX][tempY] = edges[tempY][tempX] = true;
    }
    int v1, v2;
    cin>> v1>> v2;
    
    bool *vis = new bool[V];
    for(int i=0; i<V; i++){
        vis[i] = false;
    }
    list<int> path = getPathDFS(edges, vis, V, v1, v2);
    
    for(auto it=path.begin(); it!=path.end(); it++){
        cout<< *it<< ' ';
    }
    
  return 0;
}

/*
Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/