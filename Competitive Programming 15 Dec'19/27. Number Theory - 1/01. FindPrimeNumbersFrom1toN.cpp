#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n == 1)
        return false;
    bool flag = true;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0){
            flag = false;
            break;
        }
    }
    if(flag){
        return true;
    }else{
        return false;
    }
}
int main(){
	// Write your code here
    int n, count = 0;
    cin>> n;
    for(int i=2; i<=n; i++){
        if(isPrime(i)){
            count++;
        }
    }
    cout<< count<< endl;
	return 0;
}

/*
Find Prime Numbers From 1 to N
Send Feedback
Given a number N, find number of primes in the range [1,N].
Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`
Constraints:
1≤N≤1000000
Sample Input :
3 
Sample Output -
2
*/