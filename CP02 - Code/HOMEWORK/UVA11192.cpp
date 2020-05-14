#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    string s;
    while(cin >> n, n!=0){
        cin >> s;
        int l = (int)s.size() / n;
        vector<string> listWord;
        for(int i=0; i < (int) s.size(); i+= l){
           string tmp = s.substr(i, l);
           reverse(tmp.begin(), tmp.end());
           listWord.push_back( tmp );
        }
        for(vector<string>::iterator it = listWord.begin(); it != listWord.end(); it++ ){
            cout << (*it);
        }
        cout << endl;
    }
}