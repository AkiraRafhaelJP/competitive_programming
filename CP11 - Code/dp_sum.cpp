#include <iostream>
using namespace std;

int data[] = {1, 1, 1, 1, 1, 1, 1, 1};
int sum[8]; 

int solve(int i){
	if(i == 0) return sum[i] = data[i];
	return sum[i] = data[i] + solve(i - 1);
}

int rangeSum(int L, int R){
	if(L == 0) return sum[R];
	return sum[R] - sum[L-1];	
}

int main(){
	solve(7);
	int L, R;
	while(cin >> L >> R, L != 0 || R != 0){
		cout << rangeSum(L, R) << endl;
	}
}
