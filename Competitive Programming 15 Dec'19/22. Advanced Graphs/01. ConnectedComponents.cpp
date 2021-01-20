#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> edges, vector<bool>& visited, int s, vector<int>& component){
    visited[s] = true;
    component.push_back(s);
    for(int i=0; i<edges[s].size(); i++){
        if(!visited[edges[s][i]]){
            dfs(edges, visited, edges[s][i], component);
        }
    }
}
vector<vector<int>> getComponents(vector<vector<int>> edges, int n){
    vector<bool> visited(n, false);

    vector<vector<int>> output;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(edges, visited, i, component);
            output.push_back(component);
        }
    }
    return output;
}
main(){
    int v, e;
    cin>> v>> e;
    vector<vector<int>> edges(v);
    while(e--){
        int a, b;
        cin>> a>> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    vector<vector<int>> ans = getComponents(edges, v);
    for(auto it1=ans.begin(); it1!=ans.end(); it1++){
        for(auto it2 = it1->begin(); it2!=it1->end(); it2++){
            cout<< *it2+1<< ' ';
        }
        cout<< endl;
    }
}