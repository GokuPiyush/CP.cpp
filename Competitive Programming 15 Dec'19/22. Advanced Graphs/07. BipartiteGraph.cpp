#include <bits/stdc++.h>
using namespace std;

bool bipartite(vector<int>* edges, int n){
    unordered_set<int> sets[2];
    vector<int> pending;

    sets[0].insert(0);
    pending.push_back(0);
    while(!pending.empty()){
        int current = pending.back();
        pending.pop_back();
        int currentSet = sets[0].count(current)>0? 0: 1;
        for(int i=0; i<edges[current].size(); i++){
            int neighbour = edges[current][i];
            if(sets[currentSet].count(neighbour) == 0){
                if(sets[1-currentSet].count(neighbour) == 0){
                    sets[1-currentSet].insert(neighbour);
                    pending.push_back(neighbour);
                }
            }else if(sets[currentSet].count(neighbour) > 0){
                return false;
            }
        }
    }
    return true;
}
main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        int V, E;
        cin>> V;
        if(V== 0){
            break;
        }
        cin>> E;
        vector<int>* edges = new vector<int>[V];
        while(E--){
            int a, b;
            cin>> a>> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        bool ans = bipartite(edges, V);
        ans? cout<< "YES"<< endl: cout<< "NO"<< endl;
        delete[] edges;
    }
}