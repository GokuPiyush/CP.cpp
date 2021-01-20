#include <iostream>
#include <string>
//#include "solution.h"
using namespace std;

void printKeypad(int num, string output = ""){
    if(num == 0){
        cout<< output<< endl;
        return;
    }
    if(num%10 == 1) return;
    else if(num%10 == 2){
        printKeypad(num/10, "a"+output);
        printKeypad(num/10, "b"+output);
        printKeypad(num/10, "c"+output);
    }
    else if(num%10 == 3){
        printKeypad(num/10, "d"+output);
        printKeypad(num/10, "e"+output);
        printKeypad(num/10, "f"+output);
    }
    else if(num%10 == 4){
        printKeypad(num/10, "g"+output);
        printKeypad(num/10, "h"+output);
        printKeypad(num/10, "i"+output);
    }
    else if(num%10 == 5){
        printKeypad(num/10, "j"+output);
        printKeypad(num/10, "k"+output);
        printKeypad(num/10, "l"+output);
    }
    else if(num%10 == 6){
        printKeypad(num/10, "m"+output);
        printKeypad(num/10, "n"+output);
        printKeypad(num/10, "o"+output);
    }
    else if(num%10 == 7){
        printKeypad(num/10, "p"+output);
        printKeypad(num/10, "q"+output);
        printKeypad(num/10, "r"+output);
        printKeypad(num/10, "s"+output);
    }
    else if(num%10 == 8){
        printKeypad(num/10, "t"+output);
        printKeypad(num/10, "u"+output);
        printKeypad(num/10, "v"+output);
    }
    else if(num%10 == 9){
        printKeypad(num/10, "w"+output);
        printKeypad(num/10, "x"+output);
        printKeypad(num/10, "y"+output);
        printKeypad(num/10, "z"+output);
    }
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

/*
Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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