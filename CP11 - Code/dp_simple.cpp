#include <iostream>
using namespace std;

int data[] = {1, 1, 1, 1, 1, 1, 1, 1};
int sum[8]; 

int solve(int i){
	if(i == 0) return sum[i] = data[i];
	return sum[i] = data[i] + solve(i - 1);
}

int main(){
	cout << solve(7) << endl;
}
