/*
Given an array of positive integers and an integer. Determine whether or not there exist two elements in A whose sum is exactly equal to that integer.
*/


// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool keypair(vector<int> array, int n, int x);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> array(n);
        for (int i = 0; i < n; i++) cin >> array[i];
            cout << (keypair(array, n, x) ? "Yes" : "No") << "\n";
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// A[] : the input array of positive integers
// N : size of the array arr[]
// X : the required sum
bool keypair(vector<int> A, int N, int X)
{
    // Your code goes here
    unordered_map<int, int> mp;
    for(auto i: A){
        mp[i]++;
    }
    for(auto i: A){
        if(2*i == X){
            if(mp[X-i]>1){
                return true;
            }
        }
        else if(mp[X-i]){
            return true;
        }
    }
    return false;
}
