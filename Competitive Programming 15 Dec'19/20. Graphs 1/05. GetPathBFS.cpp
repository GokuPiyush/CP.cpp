#include <bits/stdc++.h>
using namespace std;

list<int> getPathBFS(bool** edge, int V, int v1, int v2){
    bool *vis = new bool[V];
    for(int i=0; i<V; i++){
        vis[i] = false;
    }
    unordered_map<int, int> path;
    
    list<int> q;
    q.push_back(v1);
    vis[v1] = true;
    bool flag2 = false;
    while(!q.empty()){
        bool flag = false;
        int tmp = q.front();
        q.pop_front();
        for(int i=0; i<V; i++){
            if(edge[tmp][i] && !vis[i]){
                q.push_back(i);
                vis[i] = true;
                path[i] = tmp;
                if(i == v2){
                    flag = true;
                    break;
                }
            }
        }
        if(flag){
            flag2 = true;
            break;
        }
    }
    if(flag2){
        list<int> ans;
        ans.push_back(v2);
        int tmp = v2;
        while(tmp!= v1){
            tmp = path[tmp];
            ans.push_back(tmp);
        }
        return ans;
    }else{
        return {};
    }
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
    
    // Shortest Path
    list<int> path = getPathBFS(edges, V, v1, v2);
    
    for(auto it=path.begin(); it!=path.end(); it++){
        cout<< *it<< ' ';
    }

  return 0;
}

/*
Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
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