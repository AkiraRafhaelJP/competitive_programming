#include <iostream>
#include <algorithm>
#include <map> 
#include <string> 

using namespace std; 

int main(){
    int n, q;
    cin >> n;
    
    cin.ignore();
    map<string, string> mss;
    for(int i=0;i<n;i++){
        string s1, s2; 
        getline(cin, s1);
        getline(cin, s2);
        mss[s1] = s2;
    }
        
    cin >> q;    
    cin.ignore();
    for(int i=0;i<q;i++){
        string query; 
        getline(cin, query);
        cout << mss[query] << endl;
    }
    return 0;
}