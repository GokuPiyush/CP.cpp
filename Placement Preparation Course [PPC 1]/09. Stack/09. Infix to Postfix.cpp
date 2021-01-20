/*
Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
â€‹Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 
*/


// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// The main function to convert infix expression
//to postfix expression
int prec(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }
    if(ch == '*' || ch == '/'){
        return 2;
    }
    if(ch == '^'){
        return 3;
    }
    return 0;
}
string infixToPostfix(string st)
{
    // Your code here
    string ans = "";
    stack<char> s;
    for(int i=0; i<st.length(); i++){
        if(isalnum(st[i])){
            ans += st[i];
        }else if(prec(st[i])){
            while(!s.empty() && prec(s.top()) >= prec(st[i])){
                ans += s.top();
                s.pop();
            }
            s.push(st[i]);
        }else if(st[i] == '('){
            s.push('(');
        }else if(st[i] == ')'){
            while(s.top() != '('){
                ans += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    return ans;
}


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        cout<<infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends