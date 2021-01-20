/*
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. The task is to find the index of the given element K in the array A.
*/


//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int pivot(vector<int> vec, int l, int r){
    if(l>r) return -1;
    
    int m = (l+r)/2;
    if(m-1>0 && vec[m-1] > vec[m]) return m;
    if(m+1<vec.size() && vec[m] > vec[m+1]) return m+1;
    
    if(vec[l] > vec[m]) return pivot(vec, l, m-1);
    else return pivot(vec, m+1, r);
}
int bs(vector<int> vec, int k, int l, int r){
    if(l>r) return -1;
    
    int m = (l+r)/2;
    if(vec[m] > k) return bs(vec, k, l, m-1);
    else if(vec[m] < k) return bs(vec, k, m+1, r);
    else return m;
}
int Search(vector<int> vec, int K) {
    //code here
    
    int p = pivot(vec, 0, vec.size()-1);
    if(p == -1) return bs(vec, K, 0, vec.size()-1);
    int ans1 = bs(vec, K, 0, p-1);
    int ans2 = bs(vec, K, p, vec.size()-1);
    return max(ans1, ans2);
}