#include <bits/stdc++.h>
using namespace std;
#define mod 1000003

int modExp(int a, int b){
    if(a == 0 && b == 0) return -1;
    if(a == 0) return 0;
    if(b == 0) return 1;

    long long subAns = modExp(a, b/2);
    long long ans = (subAns*subAns)%mod;
    if(b%2 != 0){
        ans = (a*ans)%mod;
    }
    return ans;
}
int mmInverse(int a){
	return modExp(a, mod-2);
}
int factorial(int n){
	long long ans = mod-1;
	for(int i=n+1; i<mod; i++){
		ans = (ans*mmInverse(i))%mod;
	}
	return ans;
}
main(){
	int n = 10;
	// p should be prime
	//(p-1)!%p = p-1; => n!%p = (p-1)*((n+1)^(-1)%p)...*((p-1)^(-1)%p)
	cout<< factorial(n)<< endl;
}