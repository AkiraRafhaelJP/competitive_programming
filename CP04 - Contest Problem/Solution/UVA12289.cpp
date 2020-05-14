#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
	cin >> n;
	while(n--){
	    string s;
	    cin >> s;
	    if(s.length() == 3){
	        int one = 0, two = 0;
	        if(s[0] == 'o') one++;
	        else if(s[0] == 't') two++;
	        if(s[1] == 'n') one++;
	        else if(s[1] == 'w') two++;
	        if(s[2] == 'e') one++;
	        else if(s[2] == 'o') two++;
	        if(one >= 2) cout << 1 << endl;
	        else cout << 2 << endl;
	    }else if(s.length() == 5){
	        cout << 3 << endl;
	    }
	}
	return 0;
}