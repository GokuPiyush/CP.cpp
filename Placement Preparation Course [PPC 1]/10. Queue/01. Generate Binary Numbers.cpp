/*
Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long


 // } Driver Code Ends


// Function to print all binary numbers upto n

vector<string> generate(ll n)
{
	// Your code here
	vector<string> ans;
	for(int i=1; i<=n; i++){
	    int x=i;
	    ans.push_back("");
	    while(x){
	        if(x%2 ==0){
	            ans[ans.size()-1] = '0' + ans[ans.size()-1];
	        }else{
	            ans[ans.size()-1] = '1' + ans[ans.size()-1];
	        }
	        x /= 2;
	    }
	}
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends