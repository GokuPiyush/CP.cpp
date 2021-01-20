#include<bits/stdc++.h>
using namespace std;

struct activity{int s, e;};
bool comp(activity a, activity b){
    return a.e<b.e;
}
int main()
{
    int n;
    cin>> n;
    activity a[n];
    for(int i=0; i<n; i++){
        cin>> a[i].s>> a[i].e;
    }
    sort(a, a+n, comp);
    
    int i=1, count = 1, ns = a[i-1].e;
    while(i<n){
        if(ns<=a[i].s){
            ns = a[i].e;
            count++;
            i++;
        }else{
            while(a[i].s<ns && i<n){
                i++;
            }
        }
    }
    cout<< count<< endl;
    
    return 0;
}

/*
Activity Selection
Send Feedback
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/