/*
Given a number N, find an integer denoting the smallest number evenly divisible by each number from 1 to n.
*/


long long getSmallestDivNum(long long n);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<getSmallestDivNum(n)<<endl;
	}
	return 0;
	
}// } Driver Code Ends


/*You are required to complete this method */
long long getSmallestDivNum(long long n)
{
    long long lcm = 1;
    for(int i=2; i<=n; i++){
        lcm = (lcm * i) / __gcd(lcm, (long long)i);
    }
    return lcm;
}
