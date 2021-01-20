#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

struct triplet{int x, y, gcd;};
triplet extendedEuclid(int a, int b){
    if(b == 0){
        triplet t;
        t.x = 1, t.y = 0, t.gcd = a;
        return t;
    }
    triplet smallAns = extendedEuclid(b, a%b), ans;
    ans.x = smallAns.y;
    ans.y = smallAns.x-(a/b)*smallAns.y;
    ans.gcd = smallAns.gcd;
    return ans;
}
int mmInverse(int a){
    triplet ans = extendedEuclid(a, mod);
    return ans.x;
}
main(){
    int a = 6;
    //gcd(a,m) == 1
    //(a*ans)%m = 1; => a*ans+m*q = 1;
    if(__gcd(a, mod) == 1){
        cout<< mmInverse(a)<< endl;
    }else{
        cout<< -1<< endl;
    }
}