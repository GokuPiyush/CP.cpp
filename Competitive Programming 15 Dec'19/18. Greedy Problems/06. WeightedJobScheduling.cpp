#include<bits/stdc++.h>
using namespace std;

struct job{int s, f, p;};
bool comp(job a, job b){
    return a.f<b.f;
}
int lastNonConflictingJob(job *jb, int n, int si, int ei, int ans = -1){
    if(si>ei){
        return ans;
    }
    int mi = (si+ei)/2;
	if(jb[mi].f<=jb[n].s){
        ans = mi;
        lastNonConflictingJob(jb, n, mi+1, ei, ans);
    }else{
        lastNonConflictingJob(jb, n, si, mi-1, ans);
    }
}
int main()
{
    int n;
    cin>> n;
    job jb[n];
    for(int i=0; i<n; i++){
        cin>> jb[i].s>> jb[i].f>> jb[i].p;
    }
    sort(jb, jb+n, comp);
    int dp[n];
    dp[0] = jb[0].p;
    for(int i=1; i<n; i++){
        dp[i] = max(dp[i-1], jb[i].p);
        int id = lastNonConflictingJob(jb, i, 0, i);
        if(id !=-1){
            dp[i] = max(dp[id]+jb[i].p, dp[i-1]);
        }
    }
    cout<< dp[n-1]<< endl;
    
    return 0;
}

/*
Weighted Job Scheduling
Send Feedback
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250
*/