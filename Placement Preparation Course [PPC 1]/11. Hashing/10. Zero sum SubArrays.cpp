/*
You are given an array A[] of size N. Find the total count of sub-arrays having their sum equal to 0.
*/


//Initial function template for C++

#include<bits/stdc++.h>

using namespace std;

#define ll long long 
ll findSubarray(vector<ll> , int );

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        
        cout << findSubarray(arr,n) << "\n";
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// arr : given array 
// n : size of the given array
ll findSubarray(vector<ll> arr, int n ) {
    //code here
    unordered_map<int, int> mp;
    ll sum=0, ans=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum == 0){
            ans++;
        }
        if(mp[sum]){
            ans += mp[sum];
        }
        mp[sum]++;
    }
    
    return ans;
}
