#include<bits/stdc++.h>
using namespace std;

int kadenesAlgorithm(int ar[], int n){
    int bestSum = INT_MIN, sum = 0;
    for(int i=0; i<n; i++){
        sum += ar[i];
        if(bestSum < sum) bestSum = sum;
        if(sum < 0) sum = 0;
    }
    return bestSum;
}
int main(){
    int n = 8, ar[n] = {-5, 6, 7, -20, 3, 5, 8, -9};
    cout<< kadenesAlgorithm(ar, n)<< endl;
}