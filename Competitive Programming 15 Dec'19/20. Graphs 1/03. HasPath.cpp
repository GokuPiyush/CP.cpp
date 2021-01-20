#include <iostream>
using namespace std;

bool dfs(bool *adjMat[], bool visited[], int v, int s, int e){
    visited[s] = true;
    if(adjMat[s][e]) return true;
    for(int j=0; j<v; j++){
        if(adjMat[s][j] && !visited[j]){
            if(dfs(adjMat, visited, v, j, e)) return true;
        }
    }
    return false;
}
int main() {
    int v, e;
    cin>> v>> e;
    bool *adjMat[v];
    for(int i=0; i<v; i++){
        adjMat[i] = new bool[v];
        for(int j=0; j<v; j++)
            adjMat[i][j] = false;
    }
    for(int i=0; i<e; i++){
        int a, b;
        cin>> a>> b;
        adjMat[a][b] = adjMat[b][a] = true;
    }
    bool visited[v] = {false};
    int v1, v2;
    cin>> v1>> v2;
    string ans;
    ans = dfs(adjMat, visited, v, v1, v2)? "true": "false";
    cout<< ans<< endl;
}

/*
Code : Has Path
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
true or false
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
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/