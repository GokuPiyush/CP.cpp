#include <bits/stdc++.h>
using namespace std;

vector<int> primesTillRoot(long long r){
	int rootR = int(sqrt(r));
	bool isPrime[rootR+1];
	vector<int> prime;
	for(int i=2; i<rootR+1; i++){
		isPrime[i] = true;
	}
	for(int i=2; i*i<=rootR; i++){
		if(isPrime[i]){
			for(int j=i*i; j<=rootR; j+=i){
				isPrime[j] = false;
			}
		}
	}
    for(int i=2; i<rootR+1; i++){
		if(isPrime[i]){
			prime.push_back(i);
		}
	}
	return prime;
}
vector<long long> primesInRange(long long l, long long r){
	vector<int> prime = primesTillRoot(r);
    int n = r-l+1;
	bool isPrime[n];
	for(int i=0; i<n; i++){
		isPrime[i] = true;
	}
	for(int i=0; i<prime.size(); i++){
		long long base = (l/prime[i])*prime[i];
		if(base<l){
			base += prime[i];
		}
        if(base == prime[i]){
			base += prime[i];
		}
		for(long long j=base; j<=r; j+=prime[i]){
			isPrime[j-l] = false;
		}
	}
	vector<long long> ans;
	for(int i=0; i<n; i++){
		if(isPrime[i]){
			ans.push_back(i+l);
		}
	}
	return ans;
}
main(){
	int t;
	cin>> t;
	while(t--){
		long long l, r;
		cin>> l>> r;
		vector<long long> ans = primesInRange(l, r);
		for(auto it: ans){
			cout<< it<< endl;
		}
	}
}

/*
Segmented Sieve Problem
Send Feedback
In this problem you have to print all primes from given interval.
Input
t - the number of test cases, then t lines follows. [t <= 150]
On each line are written two integers L and U separated by a blank. L - lower bound of 
interval, U - upper bound of interval. [2 <= L < U <= 2147483647] [U-L <= 1000000].
Output
For each test case output must contain all primes from interval [L; U] in increasing order.
Sample Input:
2
2 10
3 7
Sample Output:
2
3
5
7
3
5
7 
*/