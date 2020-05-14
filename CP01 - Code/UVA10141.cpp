#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std; 

int main(){
	int n, p, caseNo = 1;
	string s;

	while(cin >> n >> p, n || p){
		string name, ans;
		double price, oldPrice = 2000000000;
		int score, oldScore = -1;
		for(int i = 0; i < n; i++){
			cin.ignore();
			getline(cin, s);	
		}
		
		for(int i = 0; i < p; i++){
			getline(cin, name);
			scanf("%lf %d\n", &price, &score);
			if(score > oldScore){
				ans = name;
				oldScore = score;
				oldPrice = price;
			}else if(score == oldScore){
				if(price < oldPrice){
					ans = name;
					oldScore = score;
					oldPrice = price;
				}
			}
			for(int j = 0; j < score; j++){
				getline(cin, s);
			}
		}
		if(caseNo > 1) 
			cout << endl;
		cout << "RFP #" << caseNo++ << endl;
		cout << ans << endl;
	}
		
	return 0;
}
