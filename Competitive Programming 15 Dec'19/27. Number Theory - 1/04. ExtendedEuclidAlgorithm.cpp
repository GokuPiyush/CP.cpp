#include <bits/stdc++.h>
using namespace std;

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
int main(){
    int a = 357, b = 234;
    //ax+by = gcd(a,b);
    triplet t = extendedEuclid(a, b);
    cout<< a<< '*'<< t.x<< " + "<< b<< '*'<< t.y<< " = "<< t.gcd<< endl;
}