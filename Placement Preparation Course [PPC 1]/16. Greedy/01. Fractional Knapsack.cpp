/*
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 
*/


#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// function to return fractionalweights
bool comp(Item a, Item b){
    return (double)a.value/a.weight > (double)b.value/b.weight;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    sort(arr, arr+n, comp);
    double ans = 0;
    for(int i=0; W!=0 && i<n; i++){
        if(arr[i].weight <= W){
            W -= arr[i].weight;
            ans += arr[i].value;
        } else{
            ans += ((double)(arr[i].value)/(arr[i].weight))*W;
            break;
        }
    }
    return ans;
}

// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends