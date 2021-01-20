/*
Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.
*/


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return if the paranthesis are balanced or not
char inv(char c){
    if(c == '}') return '{';
    if(c == ']') return '[';
    if(c == ')') return '(';
}
bool ispar(string x)
{
    // Your code here
    stack<int> s;
    for(char c: x){
        if(c=='{' || c=='(' || c=='[' ){
            s.push(c);
        }else if(!s.empty() && s.top() == inv(c)){
            s.pop();
        }else{
            return false;
        }
    }
    
    return s.empty();
}


// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends