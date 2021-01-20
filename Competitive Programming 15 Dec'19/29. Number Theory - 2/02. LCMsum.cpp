#include <bits/stdc++.h>
using namespace std;

void func(long long n){
    long long sum = 0;
	for(int i=1; i<=n; i++){
        sum += (i*n)/__gcd((long long)i,n);
    }
    cout<< sum<< endl;
}
int main(){ 
    long long n;
    scanf ( "%lld", &n );
	func(n);
    return 0;
}

/*
LCM SUM
Send Feedback
Given n, calculate and print the sum :
LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
Input Format :
Line 1 : Integer n
Output Format :
Required sum
Constraints :
1 <= T <= 300000
1 <= n <= 1000000
Sample Input 1 :
5
Sample Output 1 :
55
Sample Input 2 :
2
Sample Output 2 :
4
*/