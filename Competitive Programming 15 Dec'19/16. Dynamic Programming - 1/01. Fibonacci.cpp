#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define MAX 100
#define NIL -1

int fib[MAX];
void initialize(){
    for(int i=0; i<MAX; i++)
        fib[i] = NIL;
}
int recursive(int n){
    if(n <= 1)
        return n;
    return recursive(n-1) + recursive(n-2);
}
int memoization(int n){
    if(fib[n] == NIL)
        if(n <= 1)
            fib[n] = n;
        else
            fib[n] = memoization(n-1) + memoization(n-2);
    return fib[n];
}
int tabulation(int n){
    fib[0] = 0, fib[1] = 1;
    if(n>1)
        for(int i=2; i<=n; i++)
            fib[i] = fib[i-1] + fib[i-2];
    return fib[n];
}
int main(){
    int n = 10;
    //cin>> n;
    initialize();
    cout<< recursive(n)<< '\t'<< memoization(n)<< endl;
    
    /*auto start = high_resolution_clock::now();
    cout<< Tabulation(n)<< endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout<< "Tablutaion Time: "<< duration.count()<< endl;
    initialize();
    auto start2 = high_resolution_clock::now();
    cout<< Memoization(n)<< endl;
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2-start2);
    cout<< "Memoization Time: "<<duration2.count()<< endl;*/
}