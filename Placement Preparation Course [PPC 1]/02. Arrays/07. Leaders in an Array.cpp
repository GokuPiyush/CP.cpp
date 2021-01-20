/*
Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. 
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
	    int op[n], id = 0;
	    int max = arr[n-1];
	    for(int i=n-1;i>=0;i--){
	        if(arr[i]>=max){
	            op[id++] = arr[i];
	            max = arr[i];
	        }
	    }
	    for(int i=0;i<id;i++)
	        cout<< op[id-i-1]<< " ";
	    cout<< endl;
	}
	return 0;
}