#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N;
	while(cin >> N, N != 0){
		vector<int> vi(N+1, 0);

		int x;
		for(int i=1;i<=N;i++){
			cin >> x;
			vi[i] = vi[i-1] + x;
		}

		int max = 0;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				int tmp = vi[j] - vi[i-1];
				if(tmp > max){
					max = tmp;
				}
			}
		}

		if(max <= 0){
			cout << "Losing streak." << endl;
		}else{
			cout << "The maximum winning streak is " << max << "." << endl;
		}

	}


}