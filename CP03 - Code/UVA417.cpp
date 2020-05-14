#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

typedef set<string> ss;
ss dataSet[6];

void generateString(int pos, int length, string tmp){
    char d = 'a';
    int start = 0;
    if(pos!=1) start = tmp[pos-2] - 'a' + 1;
	for(int i=start;i<26;i++){
		tmp[pos - 1] = d + i;
		if(pos < length ){
			generateString(pos + 1, length, tmp);
		}else{
			dataSet[length].insert(tmp);
		}
	}
}

int main(){
	int last = 1, length = 1;
	
	for(int i=1; i<=5; i++){
		string s = "";
		for(int j=0; j<i; j++){
			s += "a";
		}
		generateString(1, i, s);
	}
	map<string, int> ms;
	for(int i=1;i<=5;i++){
		for(ss::iterator it = dataSet[i].begin(); it != dataSet[i].end(); it++){
			ms[ (*it) ] = last++;
		}	
	}
	string input;
	while(cin >> input){
		if(ms.find(input) != ms.end()){
			cout << ms[ input ] << endl;	
		}else{
			cout << 0 << endl;
		}
		
	}


	return 0;
}