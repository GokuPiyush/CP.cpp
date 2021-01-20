#include <bits/stdc++.h>
using namespace std;

main(){
	int n = 3;
	int pile[3] = {3, 5, 2};

	//SpragueGrundy theorem: Player 1 wins if cumXor(grundy(pile[0]), grundy(pile[1])...)!= 0
	//In this case grundy(n) = n;
	int cumXor = 0;
	for(int i=0; i<n; i++){
		cumXor ^= pile[i];
	}

	if(cumXor){
		cout<< "Player 1 will win"<< endl;
	}else{
		cout<< "Player 2 will win"<< endl;
	}
}