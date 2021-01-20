#include<bits/stdc++.h>
using namespace std;

void buildSieve(bool sieve[], int n){
    sieve[0] = sieve[1] = false;
    for(int i=2; i<=sqrt(n); i++){
        if(sieve[i]){
            for(int j=i*i; j<=n; j+=i){
                sieve[j] = false;
            }
        }
    }
}
int main(){
    int n;
    cin>> n;
    bool sieve[n+1];
    for(int i=1; i<n+1; i++){
        sieve[i] = true;
    }
    buildSieve(sieve, n+1);
    int count = 0;
    for(int i=2; i<=n; i++){
        if(sieve[i]){
            count++;
        }
    }
    cout<< count<< endl;
	return 0;
}