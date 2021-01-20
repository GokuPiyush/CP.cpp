#include <bits/stdc++.h>
using namespace std;

struct node{
    node* child[26];
    bool terminate;
    node(){
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
        terminate = false;
    }
};
node* head;

void insert(string s){
    node* tmp = head;
    for(int i=0; i<s.length(); i++){
        int pos = s[i]-'a';
        if(tmp->child[pos] == NULL){
            tmp->child[pos] = new node();
        }
        tmp = tmp->child[pos];
        if(i == s.length()-1){
            tmp->terminate = true;
        }
    }
}
void dfs(node* tmp, string s, vector<string>& ans){
    if(tmp->terminate){
        ans.push_back(s);
    }
    for(int i=0; i<26; i++){
        if(tmp->child[i] != NULL){
        	dfs(tmp->child[i], s+char(i+'a'), ans);
        }
    }
}
vector<string> suggest(string s){
    vector<string> ans;
    node* tmp = head;
    for(int i=0; i<s.length(); i++){
        int pos = s[i]-'a';
        if(tmp->child[pos] != NULL){
            tmp = tmp->child[pos];
        }else{
            ans.push_back("No suggestions");
            return ans;
        }
    }
    dfs(tmp, s, ans);
}
int main()
{
    int n;
    cin>> n;
    head = new node();
    for(int i=0; i<n; i++){
        string s;
        cin>> s;
        insert(s);
    }
    int q;
    cin>> q;
    while(q--){
        string s;
        cin>> s;
        vector<string> ans = suggest(s);
        if(ans.size() == 1 && ans[0] == "No suggestions"){
            insert(s);
            cout<< ans[0]<< endl;
        }else{
            for(auto it=ans.begin(); it!=ans.end(); it++){
                cout<< *it<< endl;
            }
        }
    }
    return 0;
}

/*
Help Me Pradyumana!
Send Feedback
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
INPUT CONSTRAINTS
1≤N≤30000
sum(len(string[i]))≤2∗10^5
1≤Q≤10^3
INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
OUTPUT FORMAT
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

NOTE: All strings are lowercase
SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn
SAMPLE OUTPUT
fact
factorial
factory
No suggestions
*/