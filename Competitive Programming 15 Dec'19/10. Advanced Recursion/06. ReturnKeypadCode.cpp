#include <iostream>
#include <string>
//#include "solution.h"
using namespace std;

int keypad(int num, string output[]){
    if(num == 0){
        output[0] = "";
        return 1;
    }
    int size = keypad(num/10, output);
    string st;
    if(num%10 == 0) return 0;
    if(num%10 == 1) return 0;
    if(num%10 == 2) st = "abc";
    if(num%10 == 3) st = "def";
    if(num%10 == 4) st = "ghi";
    if(num%10 == 5) st = "jkl";
    if(num%10 == 6) st = "mno";
    if(num%10 == 7) st = "pqrs";
    if(num%10 == 8) st = "tuv";
    if(num%10 == 9) st = "wxyz";
    string ref[size];
    for(int i=0; i<size; i++)
            ref[i] = output[i];
    int count = 0;
    for(int i=0; i<st.size(); i++)
        for(int j=0; j<size; j++)
            output[count++] = ref[j]+st[i];
    return count;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

/*
Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/