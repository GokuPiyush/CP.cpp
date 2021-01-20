/*
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
*/



using namespace std;


 // } Driver Code Ends


   

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){

    // Your code here
    int l=0, r=n-1, left=0, right=0, ans=0;
    while(l<r){
        if(arr[l]<arr[r]){
            if(arr[l]>left) left = arr[l];
            else ans += left-arr[l];
            l++;
        } else{
            if(arr[r]>right) right = arr[r];
            else ans += right-arr[r];
            r--;
        }
    }
    return ans;
}

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        //calling trappingWater() function
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends