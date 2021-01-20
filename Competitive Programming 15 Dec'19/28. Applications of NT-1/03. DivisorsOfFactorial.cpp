#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

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
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>> n;
        
        bool sieve[n+1];
        for(int i=1; i<n+1; i++){
            sieve[i] = true;
        }
        buildSieve(sieve, n+1);
        vector<int> v;
        for(int i=0; i<n+1; i++){
            if(sieve[i]){
                v.push_back(i);
            }
        }

        //Legendre's Formula: highest power of p in n! = n/p + n/p^2 + n/p^3 ...
        long long ans = 1;
        for(auto it=v.begin(); it!=v.end(); it++){
            int tmp = *it, p = 0;
        	while(tmp<=n){
                p = (p + (n/tmp)%mod)%mod;
                tmp *= *it;
            }
            ans = (ans*(p+1)%mod)%mod;
        }
        cout<< ans<< endl;
    }
    
	return 0;
}

/*
Divisors Of Factorial
Send Feedback
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input
The first line contains T, number of testcases.


T lines follows each containing the number N.
Output
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500

0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8
*/