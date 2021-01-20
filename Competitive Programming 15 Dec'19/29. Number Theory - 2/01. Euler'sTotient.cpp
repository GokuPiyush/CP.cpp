#include<bits/stdc++.h>
using namespace std;

int* eulerTotient(int n){
    int *phi = new int[n+1];
    for(int i=1; i<n+1; i++){
        phi[i] = i;
    }
    for(int i=2; i<n+1; i++){
        if(phi[i] == i){
            phi[i] = i-1;
            for(int j=2*i; j<=n; j+=i){
                phi[j] = (phi[j]*(i-1))/i;
            }
        }
    }
    return phi;
}
main(){
    int n = 10;
    //phi(n) = no of m such that gcd(n,m) = 1 and 1<=m<n;
    //phi(n) = n*(1-1/p1)*(1-1/p2)...(1-1/pk), k is no. of distict prime factors of n;
    int *phi = new int[n+1];
    phi = eulerTotient(n);
    for(int i=1; i<n+1; i++){
        cout<< phi[i]<< ' ';
    }
    cout<< endl;
}