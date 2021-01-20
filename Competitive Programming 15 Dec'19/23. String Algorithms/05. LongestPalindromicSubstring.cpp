#include <bits/stdc++.h>
using namespace std;

int lps(string s){
	int n = s.length();

	int mx = 0;
	for(int i=0; i<n; i++){
		int length = 1;
		for(int j=1; i+j<n && i-j>=0; j++){
			if(s[i+j] == s[i-j]){
				length += 2;
			}else{
				break;
			}
		}
		mx = max(mx, length);

		int l = i, r = i+1;
		length = 0;
		while(l>=0 && r<n && s[l] == s[r]){
			length += 2;
			l--, r++;
		}
		mx = max(mx, length);
	}
	
	return mx;
}
main(){
	string s = "abababece";
	//cin>> s;
	cout<< lps(s)<< endl;
}