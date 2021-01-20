#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>* edges, int start, unordered_set<int>& visited, stack<int> &finishedVert){
    visited.insert(start);
    for(int i=0; i<edges[start].size(); i++){
        if(visited.count(edges[start][i]) == 0){
            dfs(edges, edges[start][i], visited, finishedVert);
        }
    }
    finishedVert.push(start);
}
void dfs2(vector<int>* edges, int start, unordered_set<int>* component, unordered_set<int>& visited){
    visited.insert(start);
    component->insert(start);
    for(int i=0; i<edges[start].size(); i++){
        if(visited.count(edges[start][i]) == 0){
            dfs2(edges, edges[start][i], component, visited);
        }
    }
}
unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges, vector<int>* edgesT, int n){
    unordered_set<int> visited;
    stack<int> finishedVert;
    for(int i=0; i<n; i++){
        if(visited.count(i) == 0){
            dfs(edges, i, visited, finishedVert);
        }
    }
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    visited.clear();
    while(!finishedVert.empty()){
        int element = finishedVert.top();
        finishedVert.pop();
        if(visited.count(element) != 0){
            continue;
        }
        unordered_set<int>* component = new unordered_set<int>();
        dfs2(edgesT, element, component, visited);
        output->insert(component);
    }
    return output;
}
main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin>> V>> E;
    vector<int>* edges = new vector<int>[V];
    vector<int>* edgesT = new vector<int>[V];
    while(E--){
        int a, b;
        cin>> a>> b;
        edges[a-1].push_back(b-1);
        edgesT[b-1].push_back(a-1);
    }
    // Kosaraju's Algorithm
    unordered_set<unordered_set<int>*>* ans = getSCC(edges, edgesT, V);
    for(unordered_set<unordered_set<int>*>::iterator it1=ans->begin(); it1!=ans->end(); it1++){
        for(unordered_set<int>::iterator it2 = (*it1)->begin(); it2!=(*it1)->end(); it2++){
            cout<< *it2+1<< ' ';
        }
        cout<< endl;
    }

    delete ans;
    delete[] edges;
    delete[] edgesT;
}