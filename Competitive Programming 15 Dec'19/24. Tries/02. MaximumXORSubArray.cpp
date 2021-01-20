#include<bits/stdc++.h>
using namespace std;

struct trie{trie *left,*right;};
trie *head;

void insert(int x){
    trie *node = head;
    for(int i=31; i>=0; i--){
        int iBit = (x>>i)&1;
        if(iBit == 0){
            if(!node->left){
                node->left = new trie();
            }
            node = node->left;
        }else{
            if(!node->right){
                node->right = new trie();
            }
            node = node->right;
        }
    }
}
int maXor(int x){
    trie *node = head;
    int ans = 0;
    for(int i=31; i>=0; i--){
        int iBit = (x>>i)&1;
        if(iBit == 0){
            if(node->right){
                ans += pow(2,i);
                node = node->right;
            }else{
                node = node->left;
            }
        }else{
            if(node->left){
                ans += pow(2,i);
                node = node->left;
            }else{
                node = node->right;
            }
        }
    }
    return ans;
}
int main() {
    head = new trie();
    int n;
    cin>> n;
    int x = 0, MAX = -1;
    insert(x);
    for(int i=0; i<n; i++){
        int a;
        cin>> a;
        x ^= a;
        insert(x);
        int ans = maXor(x);
        if(ans>MAX) MAX = ans;
    }
    cout<< MAX<< endl;
}

/*
Maximum XOR Subarray
Send Feedback
Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7
*/