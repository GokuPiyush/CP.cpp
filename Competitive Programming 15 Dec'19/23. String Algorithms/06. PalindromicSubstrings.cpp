#include <bits/stdc++.h>
using namespace std;

int countPalindromeSubstrings(char s[]) {
	int len = strlen(s), count = 0;
	for(int i=0; i<len; i++){
        for(int j=0; i+j<len && i-j>=0; j++){
            if(s[i+j] == s[i-j]){
                count++;
            }else{
                break;
            }
        }
        int l = i, h = i+1;
        while(l>=0 && h<len){
            if(s[l] == s[h]){
                count++;
            }else{
                break;
            }
            l--, h++;
        }
    }
    return count;
}
int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}

/*
Palindromic Substrings
Send Feedback
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").
*/