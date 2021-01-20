#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin>> n;
    vector<int> x(n+2), y(n+2);
    for(int i=0; i<n; i++){
        cin>> x[i];
    }
    for(int i=0; i<n; i++){
        cin>> y[i];
    }
    
    y[n] = 0, y[n+1] = 200;
    sort(y.begin(), y.end());
    int mx = -1;
    for(int i=0; i<n+1; i++){
        mx = max(mx, y[i+1]-y[i]);
    }
	
    cout<< mx-1<< endl;
    return 0;
}

/*
Warehouse
Send Feedback
Our warehouse is square, 200 feet on each side, with solid north and south walls. The east and west walls have sliding doors which allow trucks free entry and exit. Trucks come in a variety of sizes, but the width of each truck is an integer number of feet. Unfortunately the roof is supported by posts (of negligible size).
We want to drive big trucks in a straight line into the warehouse through the west wall and (after unloading and without changing direction) out through the east wall. Find the width of the widest truck (of integral width) that can drive straight through without touching any posts (or the north or south wall). The positions of the posts are given by int[] x and int[] y: the i-th element of x and y gives the distance in feet east and north respectively from the southwest corner of the building to the i-th post.
Input Format
Integer N
Vector x of size N
Vector y of size N
Output Format
Width of Track
Constraints
x has between 1 and 50 elements inclusive
y has the same number of elements as x
each element of x and y is between 0 and 200 inclusive
Sample Testcase
3       
100 100 120
60 140 180
Returns: 79
The best path is due east, but the first and second posts are only 80 feet apart so the truck must be less than 80 feet wide.
*/