/*
Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array and return it. In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5..... (considering the increasing lexicographical order).
*/


using namespace std;
int main()
 {
	//code
	int t;
	cin>> t;
	while(t--){
	    int n;
	    cin>> n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>> arr[i];
	    for(int i=0;i<n-1;i+=2){
	        int tmp = arr[i];
	        arr[i] = arr[i+1];
	        arr[i+1] = tmp;
	    }
	    for(int i:arr)
	        cout<< i<< " ";
	    cout<< endl;
	}
	return 0;
}