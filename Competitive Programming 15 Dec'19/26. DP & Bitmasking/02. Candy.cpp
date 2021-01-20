long long solve(int like[MAXN][MAXN],int N, int mask, int pos, long long dp[])
{
	if(mask == (1<<N)-1){
        return 1;
    }
    if(dp[mask]!=-1){
        return dp[mask];
    }
    int ans = 0;
    for(int j=0; j<N; j++){
        if(like[pos][j] && !(mask&(1<<j))){
            ans += solve(like, N, mask|(1<<j), pos+1, dp);
        }
    }
    dp[mask] = ans;
    return ans;
}

main(){
    int n,like[MAXN][MAXN];
    cin>>n;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            cin>>like[i][j];
        }
    }
    long long dp[1<<N];
    memset(dp, -1, sizeof dp);
    cout<<solve(like, n, 0, 0, dp)<<endl;
}

/*
Candy
Send Feedback
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
Input Format :
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines : N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy , 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes.``
Sample Input:
3
1 1 1
1 1 1
1 1 1
Sample Output:
6
*/