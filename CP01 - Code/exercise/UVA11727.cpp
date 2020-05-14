#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
	int T, i, a, b, c, caseNo = 1;
	cin >> T;
	for(i = 0; i < T; i++){
		cin >> a >> b >> c;
		int s = -1;
		if(a > b && b > c || c > b && b > a){
			s = b;
		}else if(b > a && a > c || c > a && a > b){
			s = a;
		}else if(a > c && c > b || b > c && c > a){
			s = c;
		}
		cout << "Case " << caseNo++ << ": " << s << endl;
	}
	return 0;
}