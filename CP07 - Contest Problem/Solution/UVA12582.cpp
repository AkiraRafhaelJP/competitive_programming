#include <iostream>
#include <string> 
#include <map>
#include <stack>
using namespace std;

int main(){
    int n, tc=1;
    string s;
    cin >> n;
    while(n--){
        cin >> s;int X=s.length();
        map<char, int> mp;
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<X;i++){
            char c = s[i];
            if(st.size() != 0){
                if(st.top() == c){
                    st.pop();
                    continue;
                }else{
                    if( mp.find(c) == mp.end() ){
                        mp[c] = 1;
                        mp[st.top()] += 1;
                    }else{
                        mp[c] += 1;
                        mp[st.top()] += 1;
                    } 
                    
                }
            }
            st.push(c);
            
        }
        map<char, int>::iterator it;
        cout << "Case " << tc++ << endl;
        for(it = mp.begin(); it!= mp.end(); it++){
            cout << (*it).first << " = " << (*it).second << endl;
        }
    }
    
    return 0;
}
