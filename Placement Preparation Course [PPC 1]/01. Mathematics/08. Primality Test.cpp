/*
A prime number is a number which is only divisible by 1 and itself.
Given number N check if it is prime or not.
*/


//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//You need to complete this function
bool isPrime(int N)
{
    //Your code here
    bool prime = true;
    for(int i=2; i*i<=N; i++){
        if(N%i == 0){
            prime = false;
            break;
        }
    }
    return prime;
}


// { Driver Code Starts.

int main()
{
    int T; //testcases
    cin>>T; //input testcases
    while(T--) //while testcase have not been exhausted
    {
        int N;
        cin>>N; //input n
        
        if(isPrime(N)) 
        cout<<"Yes";
        else
            cout<<"No";
            
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends