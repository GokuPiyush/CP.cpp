/*
You are given a string. You need to print the lexicographically sorted power-set of the string.
Note: The string s contains lowercase letter of alphabet.
*/


//Initial Template for C++


// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//Complete this function
vector <string> powerSet(string s)
{
   //Your code here
   if(s.length() == 0){
       vector<string> ans;
       ans.push_back(s);
       return ans;
   }
   int n = s.length();
   string s1 = s.substr(0,n-1), s2 = s.substr(n-1,1);
   vector<string> ans1 = powerSet(s1), ans2, ans;
   for(auto i: ans1){
       ans2.push_back(i+s2);
   }
   for(auto x: ans1) ans.push_back(x);
   for(auto x: ans2) ans.push_back(x);
   return ans;
}


// { Driver Code Starts.


// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        vector<string> ans = powerSet(s);
        sort(ans.begin(),ans.end());
        for(auto x:ans)
        cout<<x<<" ";
        cout<<endl;
        
        
    }

return 0;
}   // } Driver Code Ends