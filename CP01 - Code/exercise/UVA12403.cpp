#include <iostream>
#include <string>

using namespace std;

int main(){
	int T, total = 0;
	cin >> T; 
	while(T--){
		string word; 
		int donation; 
		cin >> word; 
		if(word == "donate"){
			cin >> donation; 
			total += donation;
		}else if(word == "report"){
			cout << total << endl;
		}
	}
	return 0;
}