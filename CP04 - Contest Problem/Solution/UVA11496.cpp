#include <iostream>
#include <vector>

using namespace std;

int main(){
	int T;
	while(cin >> T, T){
		vector<int> v; 
		for(int i=0;i<T;i++){
			int x;
			cin >> x;
			v.push_back(x);
		}
		int peak = 0;
		for(int i=0;i<T;i++){
			if(i == 0){
				if( (v[i+1] < v[i] && v[T-1] < v[i]) || (v[i+1] > v[i] && v[T-1] > v[i]) ){
					peak++;
				}
			}else if(i == T-1){
				if( (v[i-1] < v[i] && v[0] < v[i]) || (v[i-1] > v[i] && v[0] > v[i]) ){
					peak++;
				}
			}else if( (v[i-1] < v[i] && v[i+1] < v[i]) || (v[i-1] > v[i] && v[i+1] > v[i]) ){
					peak++;
				}
		}
		cout << peak << endl;
	}
}