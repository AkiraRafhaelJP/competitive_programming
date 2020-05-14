#include <iostream>
#include <cstdio> 
#include <string>
#include <cstring> 
#include <stack> 
using namespace std; 
int main(){
	int T = 0, caseNo = 1;
	cin >> T;
	while(T--){
		stack<string> sA, sB;
		string s;
		for(int i=0; i<52; i++){
			cin >> s;
			sA.push(s);
		}
		for(int i=0; i<25; i++){
			sB.push(sA.top());
			sA.pop();
		}
		int Y = 0;
		for(int i=0; i<3;i++){
			int value = 0;
			string topCard = sA.top();
			if(topCard[0] == 'A' || 
			   topCard[0] == 'K' || 
			   topCard[0] == 'Q' || 
			   topCard[0] == 'J' || 
			   topCard[0] == 'T' ){
				value = 10;
			}else{
				value = (int) topCard[0] - 48;
			}

			Y += (int) value;
			int X = 10 - value + 1;
			for(int j=0; j<X; j++){
				sA.pop();
			}
		}
		while(!sA.empty()){
			sB.push(sA.top());
			sA.pop();
		}
		for(int i=0; i<Y-1; i++){
			sB.pop();
		}
		cout << "Case " << caseNo++ << ": " << sB.top() << endl;
	}
}
