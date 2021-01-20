/*
Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.
*/


#include<bits/stdc++.h>
using namespace std;

int maxDistance(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<maxDistance(arr,n)<<endl;
    }
    return 0;
}// } Driver Code Ends


// your task is to complete this function
int maxDistance(int arr[], int n)
{
//Code here
    unordered_map<int, int> mp;
    int MAX = 0;
    for(int i=0; i<n; i++){
        if(mp[arr[i]]){
            MAX = max(MAX, i+1-mp[arr[i]]);
        }else{
            mp[arr[i]] = i+1;
        }
    }
    
    return MAX;
}