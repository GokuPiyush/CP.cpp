#include<iostream>
using namespace std;


int firstIndex( const int ar[], int n, int target )
{
    if(n-1<0) return -1;
    if(ar[0] == target) return 0;
    int ans = firstIndex(ar+1, n-1, target);
    return ans==-1?ans:1+ans;
}
int allIndexes(int input[], int size, int x, int output[], int count=0) {
    if(size<=0) return 0;
    
    int ans = firstIndex(input, size, x);
    if(ans == -1){
        return 0;
    }else{
        if(count == 0){
            output[0] = ans;
        }else{
            output[0] = ans + *(output-1) + 1;
        }
        return 1 + allIndexes(input+ans+1, size-ans-1, x, output+1, count+1);
    }
}
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}

/*
All Indices of Number
Send Feedback
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4
*/