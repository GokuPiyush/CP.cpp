/*
Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size N and M respectively, find their union.
*/


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//arr1,arr2 : the arrays
// n, m: size of arrays
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    //Your code here
    //return vector with correct order of elements
    vector<int> ans;
    unordered_map<int, int> mp;
    int i, j;
    for(i=0, j=0; i<n && j<m; ){
        if(arr1[i]<arr2[j]){
            if(mp[arr1[i]] == 0){
                mp[arr1[i]]++;
                ans.push_back(arr1[i]);
            }
            i++;
        } else if(arr1[i]>arr2[j]){
            if(mp[arr2[j]] == 0){
                mp[arr2[j]]++;
                ans.push_back(arr2[j]);
            }
            j++;
        } else{
            if(mp[arr1[i]] == 0){
                mp[arr1[i]]++;
                ans.push_back(arr1[i]);
            }
            i++, j++;
        }
    }
    for( ;i<n; i++){
        if(mp[arr1[i]] == 0){
            mp[arr1[i]]++;
            ans.push_back(arr1[i]);
        }
    }
    for( ;j<m; j++){
        if(mp[arr2[j]] == 0){
            mp[arr2[j]]++;
            ans.push_back(arr2[j]);
        }
    }
    return ans;
}

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    
	    vector<int> ans = findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends