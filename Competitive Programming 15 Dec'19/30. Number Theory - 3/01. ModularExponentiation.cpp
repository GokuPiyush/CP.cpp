#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int modExp(int a, int b){
    if(a == 0 && b == 0) return -1;
    if(a == 0) return 0;
    if(b == 0) return 1;

    long long smallAns = modExp(a,b/2);
    long long ans = (smallAns*smallAns)%mod;
    if(b%2 != 0){
        ans = (a*ans)%mod;
    }
    return int(ans);
}
main(){
    int a = -5, b = 3;
    cout<< modExp(a, b)<< endl;
}