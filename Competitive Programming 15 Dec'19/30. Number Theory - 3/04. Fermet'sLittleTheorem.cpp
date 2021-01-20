#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

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
main(){
	int a = 5;
	// p should be prime
	// (a^p)%p = a; => (a^(p-2))%p = a^(-1);
	cout<< mmInverse(a)<< endl;
}