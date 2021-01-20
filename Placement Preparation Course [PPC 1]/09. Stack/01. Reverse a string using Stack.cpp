/*
You are given a string S, the task is to reverse the string using stack.
*/


#include<bits/stdc++.h>
using namespace std;
void reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        reverse(str,len);
        cout<<str;
        cout<<endl;
    }
        return 0;
}
// } Driver Code Ends


void reverse(char *str, int len)
{

// Your code goes here
    stack<char> s;
    s.push('\0');
    for(int i=0; i<len; i++){
        s.push(str[i]);
    }
    int i=0;
    while(!s.empty()){
        str[i++] = s.top();
        s.pop();
    }

}