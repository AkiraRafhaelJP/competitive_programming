#include <iostream>

using namespace std;

long long memo[1000];
long long fibo(int n){
	if(n == 0 || n == 1) return 1LL;
	if(memo[n] != 0) return memo[n];
	return memo[n] = fibo(n-1) + fibo(n-2);
}

int main(){
	int n;
	cin >> n;
	cout << fibo(n) << endl;
}