/*
Given a string S. The task is to find all permutations of a given string.
*/


#include<bits/stdc++.h>
using namespace std;

void permutation(string S);

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		permutation(S);
		cout<<endl;
	
	}
	return 0;
}// } Driver Code Ends


//Complete this function
void helper(string s, vector<string>& ans, int i=0){
    if(i==s.length()){
        ans.push_back(s);
        return;
    }
    for(int j=i; j<s.length(); j++){
        swap(s[i], s[j]);
        helper(s, ans, i+1);
        swap(s[i], s[j]);
    }
}
void permutation(string S)
{
    
    //Your code here
    vector<string> ans;
    helper(S, ans);
    sort(ans.begin(), ans.end());
    for(auto x: ans){
        cout<< x<< ' ';
    }
}