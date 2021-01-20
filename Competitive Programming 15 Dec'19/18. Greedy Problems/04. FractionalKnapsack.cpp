#include<bits/stdc++.h>
using namespace std;

struct item{int value, weight;};
bool comp(item a, item b){
	return (double)a.value/a.weight > (double)b.value/b.weight;
}
double fknapsack(item *ar, int n, int w){
	sort(ar, ar+n, comp);
	int currW = 0; double fvalue = 0;
	for(int i=0; i<n; i++){
		if(currW+ar[i].weight<=w){
			currW += ar[i].weight;
			fvalue += ar[i].value;
		}else{
			int rWeight = w-currW;
			fvalue += ((double)ar[i].value/ar[i].weight)*rWeight;
			break;
		}
	}
	return fvalue;
}
main(){
	int n = 3, w = 70;
	item ar[n] = {{60, 20}, {70, 15}, {80, 40}};
	cout<< fknapsack(ar, n, w)<< endl;
}