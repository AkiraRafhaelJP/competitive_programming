#include <iostream>
#include <string> 
#include <set>
#include <cctype>

using namespace std;

int main(){
    string s;
    set<string> dict;
    while(getline(cin, s) ){
        string word = "";
        int pos = 0;
        for(int i=0;i<s.length();i++){
            if( isalpha(s[i]) ){
                
                word += tolower(s[i]);
                pos++;
            }else if(pos != 0){
                dict.insert( word );
                pos = 0;
                word = "";
                
            }
        }
        if(pos != 0){
            dict.insert( word );
            pos = 0;
            word = "";
        }
        
    }
    for( set<string>::iterator it = dict.begin(); it != dict.end(); it++){
        cout << *it << endl;
    }
    
    
    return 0;
}
