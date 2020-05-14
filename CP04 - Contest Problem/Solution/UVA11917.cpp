#include <iostream>
#include <map>

using namespace std;

int main(){
	int T; 
	cin >> T; 
	for(int i=1;i<=T;i++){
		int N;
		map<string, int> mp; 

		cin >> N;
		string s;
		int d;
		for(int j=0;j<N;j++){
			cin >> s >> d;
			mp[s] = d;
		}
		string S;
		int D;
		cin >> D; cin >> S;
		if(mp.find(S) == mp.end()){
			cout << "Case " << i << ": Do your own homework!" << endl;
		}else{
			if(mp[S] <= D)
				cout << "Case " << i << ": Yesss" << endl;
			else if(mp[S] <= D+5)
				cout << "Case " << i << ": Late" << endl;
			else 
				cout << "Case " << i << ": Do your own homework!" << endl;	
		}
	}
}