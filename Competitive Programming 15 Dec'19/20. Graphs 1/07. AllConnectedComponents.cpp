#include <bits/stdc++.h>
using namespace std;

void connectedComponents(bool **adjMat, bool *visited, int v, int s, vector<int> &ans){
    visited[s] = true;
    // cout<< s<< endl;
    ans.push_back(s);
    for(int i=0; i<v; i++)
        if(adjMat[s][i] && !visited[i])
            connectedComponents(adjMat, visited, v, i, ans);
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
    vector<int> ans;
    while(true){
        int flag = false;
        ans.clear();
        for(int i=0; i<V; i++){
            if(!visited[i]){
                connectedComponents(adjMat, visited, V, i, ans);
                flag = true;
                break;
            }
        }
        sort(ans.begin(), ans.end());
        for(auto it = ans.begin(); it!=ans.end(); it++)
            cout<< *it<< ' ';
        cout<< endl;
        if(!flag) break;
    }
  return 0;
}

/*
Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
Different components in new line
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/