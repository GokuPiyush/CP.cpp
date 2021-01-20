#include<cstring>
using namespace std;
#define mod 1000000007

void multiply(long long a[2][2], long long b[2][2]){
	long long t1 = ((a[0][0]*b[0][0])%mod+(a[0][1]*b[1][0])%mod)%mod;
	long long t2 = ((a[0][0]*b[0][1])%mod+(a[0][1]*b[1][1])%mod)%mod;
	long long t3 = ((a[1][0]*b[0][0])%mod+(a[1][1]*b[1][0])%mod)%mod;
	long long t4 = ((a[1][0]*b[0][1])%mod+(a[1][1]*b[1][1])%mod)%mod;

	a[0][0] = t1, a[0][1] = t2, a[1][0] = t3, a[1][1] = t4;
}
void power(long long a[2][2], long long n){
	if(n == 1){
		return;
	}
	power(a, n/2);
	multiply(a, a);
	if(n%2 != 0){
		long long m[2][2] = {{1, 1}, {1, 0}};
		multiply(a, m);
	}
}
long long fib(long long n){
	long long a[2][2] = {{1, 1}, {1, 0}};
	if(n == 0){
		return 0;
	}
	power(a, n);
	return a[0][0]*0+a[0][1]*1;
}

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
    long long sum = 0;
	for(long long i=m; i<=n; i++){
        sum = (sum+fib(i)%mod)%mod;
    }
    return sum;
}

int main()
{
    unsigned long long m,n;
    cin>>m>>n;
	cout<<fiboSum(m,n);
    return 0;
}

/*
Fibonacci Sum
Send Feedback
The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Input Format :
Two non-negative integers N and M. (N <= M)
Output Format :
A single line containing the answer for the task.
Sample Input :
10 
19
Sample Output :
10857
*/