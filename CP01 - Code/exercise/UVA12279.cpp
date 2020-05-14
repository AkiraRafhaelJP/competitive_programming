#include <iostream>

using namespace std;

int main() {
    int T = 1, N, data; 
    while(cin >> N && N != 0){
        int balance = 0;
        for(int i=0;i<N;i++){
            cin >> data;
            if(data != 0) balance++;
            else balance--;
        }
        cout << "Case " << T++ << ": " << balance << endl;
    }
	return 0;
}