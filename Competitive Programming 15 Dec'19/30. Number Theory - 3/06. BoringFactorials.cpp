#include <bits/stdc++.h>
using namespace std;

int modExp(int a, int b, int mod){
    if(a == 0 && b == 0) return -1;
    if(a == 0) return 0;
    if(b == 0) return 1;

    long long subAns = modExp(a, b/2, mod);
    long long ans = (subAns*subAns)%mod;
    if(b%2 != 0){
        ans = (a*ans)%mod;
    }
    return ans;
}
int mmInverse(int a, int mod){
	return modExp(a, mod-2, mod);
}
int factorial(int n, int mod){
    if(mod<=n){
        return 0;
    }
	long long ans = mod-1;
	for(int i=n+1; i<mod; i++){
		ans = (ans*mmInverse(i, mod))%mod;
	}
	return ans;
}
main(){
	int n = 10;
	int t;
    cin>> t;
    while(t--){
        int n, p;
        cin>> n>> p;
        cout<< factorial(n, p)<< endl;
    }
}

/*
Boring Factorials
Send Feedback
Sameer and Arpit want to overcome their fear of Maths and so they have been recently practicing Maths problems a lot. Aman, their friend has been helping them out. But as it goes, Sameer and Arpit have got bored of problems involving factorials. Reason being, the factorials are too easy to calculate in problems as they only require the residue modulo some prime and that is easy to calculate in linear time. So to make things interesting for them, Aman - The Mathemagician, gives them an interesting task. He gives them a prime number P and an integer N close to P, and asks them to find N! modulo P. He asks T such queries.
Input
First line contains an integer T, the number of queries asked.

Next T lines contains T queries of the form “N P”. (quotes for clarity)
Output
Output exactly T lines, containing N! modulo P.
Constraints:
1 <= T <= 1000

1 < P <= 2*10^9

1 <= N <= 2*10^9

Abs(N-P) <= 1000
Sample Input:
3
2 5
5 11
21 71
Sample Output:
2
10
6
*/