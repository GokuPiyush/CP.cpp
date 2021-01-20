/*
Given an array A of integers. Find the length of the longest sub-sequence such that elements in the sub-sequence are consecutive integers, the consecutive numbers can be in any order.
*/


#include <bits/stdc++.h>

using namespace std;

int findLongestConseqSubseq(int [], int );

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int a[n];
		
		// input array elements
		for(int i=0;i<n;i++)
		    cin>>a[i];
		
		cout<< findLongestConseqSubseq(a, n)<<endl;
		
	}
	return 0;
}// } Driver Code Ends




// function to find longest consecutive subsequence
// n : size of array
// arr[] : input array
int findLongestConseqSubseq(int arr[], int n)
{
    //Your code here
    unordered_map<int, int> mp;
    int MAX = INT_MIN, MIN = INT_MAX;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
        MAX = max(MAX, arr[i]);
        MIN = min(MIN, arr[i]);
    }
    
    int lcs = 0, cs = 0;
    for(int i=MIN; i<=MAX; i++){
        if(mp[i]){
            cs++;
            lcs = max(lcs, cs);
        }else{
            cs = 0;
        }
    }
    
    return lcs;
}