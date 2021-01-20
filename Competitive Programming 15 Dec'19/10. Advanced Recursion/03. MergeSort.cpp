#include <iostream>
//#include "solution.h"
using namespace std;

void mergeSort(int input[], int ei, int si=0){
    ei -= 1;
    if(si >= ei) return;
	int mi = (si+ei)/2;
    mergeSort(input, mi+1, si);
    mergeSort(input, ei+1, mi+1);
    int ref[ei-si+1], li=si, ri=mi+1, i;
    for(i=0; li<=mi && ri<=ei; i++)
        if(input[li]<input[ri])
            ref[i] = input[li], li++;
        else
            ref[i] = input[ri], ri++;
    for(i; i<ei-si+1; i++)
        ref[i] = li>mi? input[ri++]: input[li++];
    for(int i=si; i<=ei; i++)
        input[i] = ref[i-si];
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}

/*
Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/