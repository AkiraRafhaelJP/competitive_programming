#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;

int main(){
	int T; 
	cin >> T;
	while(T--){
		int X, n; 
		vector<int> P;
		cin >> X >> n;
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			P.push_back(x);
		}
		bool found = false;
		for(int i=0;i < (1 << n); i++){
			int sum = 0;
			for(int j=0;j<n;j++){
				if(i & (1 << j)){
					sum+= P[j];
				}
			}
			if(sum == X){
				found = true;
				break;
			}
		}
		if(found) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	

}