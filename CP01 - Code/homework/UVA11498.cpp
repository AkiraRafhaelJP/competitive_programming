#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
	int K, i, N, M, X[1001], Y[1001];
	while(cin >> K, K != 0){
		cin >> N >> M;
		for(i = 0; i < K; i ++){
			cin >> X[i] >> Y[i];
			if(X[i] == N || Y[i] == M){
				cout << "divisa" << endl;
			}else if(X[i] > N && Y[i] > M){
				cout << "NE" << endl;
			}else if(X[i] < N && Y[i] > M){
				cout << "NO" << endl;
			}else if(X[i] < N && Y[i] < M){
				cout << "SO" << endl;
			}else if(X[i] > N && Y[i] < M){
				cout << "SE" << endl;
			}
		}
	}

	return 0;
}