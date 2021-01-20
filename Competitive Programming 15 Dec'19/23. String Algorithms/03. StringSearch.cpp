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
int findString(char text[], char pattern[]) {
    int n = strlen(text), m = strlen(pattern);
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
		return i-j;
	}else{
		return -1;
	}
}

int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}

/*
String Search
Send Feedback
Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
Input format :

Line 1 : String S

Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1
*/