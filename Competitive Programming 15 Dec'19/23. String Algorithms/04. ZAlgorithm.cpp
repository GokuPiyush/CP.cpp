#include <bits/stdc++.h>
using namespace std;

void buildZ(int z[], string st){
	int n = st.length(), l=0, r=0;
	for(int i=1; i<n; i++){
		if(i>r){
			l = r = i;
			while(r<n && st[r-l] == st[r]){
				r++;
			}
			z[i] = r-l;
			r--;
		}else{
			int k = i-l;
			if(z[k] <= r-i){
				z[i] = z[k];
			}else{
				l = i;
				while(r<n && st[r-l] == st[r]){
					r++;
				}
				z[i] = r-l;
				r--;
			}
		}
	}
}
void searchString(string text, string pattern){
	string st = pattern+"$"+text;
	int n = st.length();
	int z[n];
	buildZ(z, st);
	for(int i=0; i<n; i++){
		if(z[i] == pattern.length()){
			cout<< i-pattern.length()-1<< ' ';
		}
	}
	cout<< endl;
}
main(){
	string text = "abcdsafbcdsafbcda", pattern = "bcd";
	//cin>> text>> pattern;

	searchString(text, pattern);
}