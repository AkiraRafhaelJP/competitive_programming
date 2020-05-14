#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef long long ll;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a * (b/gcd(a,b)) ; }

int main(){
	int a, b;
	a = 6;
	b = 8;
	cout << "gcd : " << gcd(a, b) << endl;
	cout << "lcm : " << lcm(a, b) << endl;
	return 0;
}