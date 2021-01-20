#include <bits/stdc++.h>
using namespace std;
typedef vector<complex<double>> vecomplex;

vecomplex initOmega(long long n){
	vecomplex omega(n);
	for(long long i=0; i<n; i++){
		double theta = (2*acos(-1)/n)*i;
		omega[i] = complex<double>(cos(theta), sin(theta));
	}
	return omega;
}
vecomplex fft(vecomplex &a, vecomplex &omega){
	long long n = (long long)a.size();
	if(n == 1){
		return a;
	}
	vecomplex aeven(n/2);
	vecomplex aodd(n/2);
	for(int i=0,j=0; i<n; i+=2,j++){
		aeven[j] = a[i];
		aodd[j] = a[i+1];
	}
	vecomplex yeven = fft(aeven, omega);
	vecomplex yodd = fft(aodd, omega);
	vecomplex y(n);
	for(int i=0; i<n/2; i++){
		y[i] = yeven[i] + omega[i]*yodd[i];
		y[i+n/2] = yeven[i] - omega[i]*yodd[i];
	}
	return y;
}
main(){
	vecomplex a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	vecomplex omega = initOmega(a.size());
	vecomplex y = fft(a, omega);

	for(int i=0; i<y.size(); i++){
		cout<< y[i]<< endl;
	}

	// rest remaining
}