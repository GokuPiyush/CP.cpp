#include <bits/stdc++.h>
using namespace std;

struct node{
    node* child[26];
    int wt;
    node(){
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
        wt = 0;
    }
};
node* head;

void insert(string st, int wt){
    node* tmp = head;
    for(int i=0; i<st.length(); i++){
        int pos = st[i]-'a';
        if(tmp->child[pos] == NULL){
            node* nd = new node();
            tmp->child[pos] = nd;
            tmp = nd;
            tmp->wt = wt;
        }else{
            tmp = tmp->child[pos];
            if(tmp->wt < wt){
            	tmp->wt = wt;
        	}
        }
    }
}
int search(string st){
    node* tmp = head;
    for(int i=0; i<st.length(); i++){
        int pos = st[i]-'a';
        if(tmp->child[pos] != NULL){
            tmp = tmp->child[pos];
        }else{
            return -1;
        }
    }
    return tmp->wt;
}

int main()
{
    int n, q;
    cin>> n>> q;
    head = new node();
    for(int i=0; i<n; i++){
        string st; int wt;
        cin>> st>> wt;
        insert(st, wt);
    }
    while(q--){
        string t;
        cin>> t;
        cout<< search(t)<< endl;
    }
    return 0;
}

/*
Search Engine
Send Feedback
Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
INPUT
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.
OUTPUT
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
CONSTRAINTS
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
total length of all strings in database entries ≤ 10^6
total length of all query strings ≤ 10^6
SAMPLE INPUT
2 1
hackerearth 10
hackerrank 9
hacker
SAMPLE OUTPUT
10
*/