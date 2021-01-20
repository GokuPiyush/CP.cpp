#include <bits/stdc++.h>
using namespace std;

bool isMatching(string s, string p){
	int n = s.length(), m = p.length();

	for(int i=0; i<n-m+1; i++){
		bool isFound = true;
		for(int j=0; j<m; j++){
			if(s[i+j] == p[j]){
				continue;
			}else{
				isFound = false;
				break;
			}
		}
		if(isFound){
			return true;
		}
	}
	return false;
}
main(){
	string s = "fsagfsagsag", p = "gsag";
	//cin>> s>> p;
	cout<< isMatching(s, p)<< endl;
}