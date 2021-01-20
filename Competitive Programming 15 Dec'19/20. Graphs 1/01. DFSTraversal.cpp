#include <bits/stdc++.h>
using namespace std;

void print(int** edges, bool* visited, int n, int s=0){
    cout<< s<< endl;
    visited[s] = true;
    for(int i=0; i<n; i++){
        if(i == s){
            continue;
        }
        if(edges[s][i] == 1){
            if(visited[i]){
                continue;
            }
            print(edges, visited, n, i);
        }
    }
}
main(){

    int n, e;
    cin>> n>> e;
    int** edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0; i<e; i++){
        int f, s;
        cin>> f>> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    print(edges, visited, n);
}