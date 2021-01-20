#include<iostream>
//#include "Solution.h"
using namespace std;


void quickSort(int input[], int ei, int si = 0) {
    ei -= 1;
    if(si>=ei) return;
    int pivot = input[ei], i = si-1;
    for(int j = si; j<=ei-1; j++)
        if(input[j]<pivot){
            i++;
            int tmp = input[i];
            input[i] = input[j], input[j] = tmp;
        }
    int pi = i+1, tmp = input[pi];
    input[pi] = pivot, input[ei] = tmp;
    quickSort(input, pi, si);
    quickSort(input, ei+1, pi+1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


/*
Quick Sort Code
Send Feedback
Sort an array A using Quick Sort.
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
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/