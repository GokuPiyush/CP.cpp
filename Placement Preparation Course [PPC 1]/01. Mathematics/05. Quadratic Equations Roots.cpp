/*
Given a quadratic equation in the form ax2 + bx + c. Find its roots.
*/


//Initial Template for C++
/* C++ program to find roots of a quadratic equation */
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//You need to complete this function
void quadraticRoots(int a,int b, int c)
{
   
   //Your code here
   double d = b*b - 4*a*c;
   if(d < 0){
       cout<< "Imaginary";
   }else{
       double root1 = floor((-b + sqrt(d)) / (2*a)), root2 = floor((-b - sqrt(d)) / (2*a));
       if(root1 == -0){
           root1 = 0;
       }
       if(root2 == -0){
           root2 = 0;
       }
       cout<< max(root1, root2)<< ' '<< min(root1, root2);
   }
   
   
   // Your don't need to printline
   // It will automatically be 
   // handled by driver code
}



// { Driver Code Starts.

int main() {
	int T; 
	cin>>T; //input number of testcases
	
	while(T--)
	{
	    int a, b, c; 
	    cin>>a>>b>>c; //Input a, b, and c
	    
	    quadraticRoots(a,b,c);
	    cout<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends