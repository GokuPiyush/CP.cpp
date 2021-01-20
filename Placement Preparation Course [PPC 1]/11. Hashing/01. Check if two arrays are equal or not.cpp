/*
Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not. Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) of elements may be different though.
Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.
*/


//Initial function template for C++

#include<bits/stdc++.h>

using namespace std;
#define ll long long 

bool check(vector<ll> , vector<ll> , int );

int main()
 {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        vector<ll> arr(n,0),brr(n,0);
        
        // increase the count of elements in first array
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        
        
        // iterate through another array
        // and decrement the count of elements
        // in the map in which frequency of elements
        // is stored for first array
        for(ll i=0;i<n;i++)
            cin >> brr[i];
        
        cout << check(arr,brr,n) << "\n";
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// arr : 1st given array
// brr : 2nd given array
// n : size of both the arrays

bool check(vector<ll> arr, vector<ll> brr, int n) {
    //code here
    unordered_map<int, int> mp1, mp2;
    for(auto i: arr){
        mp1[i]++;
    }
    for(auto i: brr){
        mp2[i]++;
    }
    
    bool flag = true;
    for(auto it=mp1.begin(); it!=mp1.end(); it++){
        if(it->second != mp2[it->first]){
            flag = false;
            break;
        }
    }
    
    return flag;
}