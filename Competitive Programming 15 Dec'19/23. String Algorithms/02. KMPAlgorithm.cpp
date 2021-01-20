#include <bits/stdc++.h>
using namespace std;

int* getLps(string pattern){
	int m = pattern.length();
	int* lps = new int[m];
	lps[0] = 0;
	int i=1, j=0;
	while(i<m){
		if(pattern[i] == pattern[j]){
			lps[i] = j+1;
			i++,j++;
		}else{
			if(j != 0){
				j = lps[j-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}
bool kmpSearch(string text, string pattern){
	int n = text.length(), m = pattern.length();
	int* lps = new int[m];
	lps = getLps(pattern);
	int i=0, j=0;
	while(i<n && j<m){
		if(text[i] == pattern[j]){
			i++, j++;
		}else{
			if(j != 0){
				j = lps[j-1];
			}else{
				i++;
			}
		}
	}
	if(j == m){
		return true;
	}else{
		return false;
	}
}
main(){
	string text = "abcxabcdabcdabcy", pattern = "abcdabcy";
	//cin>> text>> pattern;
	cout<< kmpSearch(text, pattern)<< endl;
}