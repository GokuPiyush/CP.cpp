/*
Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.
*/


// C++ program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// The main function that returns value of a given postfix expression

int evaluatePostfix(string &str)
{
    // Your code here
    
    stack<int> s;
    for(char c: str){
        if(!isdigit(c)){
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            int ans;
            if(c == '*'){
                ans = op1*op2;
            }else if(c == '/'){
                ans = op1/op2;
            }else if(c == '+'){
                ans = op1+op2;
            }else if(c == '-'){
                ans = op1-op2;
            }
            s.push(ans);
        }
        else{
            s.push(c-'0');
        }
    }
    return s.top();
}


// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string str;
        cin>>str;
    
    cout<<evaluatePostfix(str)<<endl;
    }
    return 0;
}
  // } Driver Code Ends