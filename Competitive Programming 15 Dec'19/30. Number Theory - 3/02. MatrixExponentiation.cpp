#include <bits/stdc++.h>
using namespace std;

void multiply(int a[2][2], int b[2][2]){
	int t1 = a[0][0]*b[0][0]+a[0][1]*b[1][0];
	int t2 = a[0][0]*b[0][1]+a[0][1]*b[1][1];
	int t3 = a[1][0]*b[0][0]+a[1][1]*b[1][0];
	int t4 = a[1][0]*b[0][1]+a[1][1]*b[1][1];

	a[0][0] = t1, a[0][1] = t2, a[1][0] = t3, a[1][1] = t4;
}
void power(int a[2][2], int n){
	if(n == 1){
		return;
	}
	power(a, n/2);
	multiply(a, a);
	if(n%2 != 0){
		int m[2][2] = {{1, 1}, {1, 0}};
		multiply(a, m);
	}
}
int fib(int n){
	int a[2][2] = {{1, 1}, {1, 0}};
	if(n == 0){
		return 0;
	}
	power(a, n);
	return a[0][0]*0+a[0][1]*1;
}

main(){
	int n = 10;
	// a[0][0]*fib[0]+a[0][1]*fib[1] = fib[1];
	cout<< fib(n-1)<< endl;
}