#include <iostream>
#include <stack>
#include <string>
#include <set>
#include <vector>
using namespace std;
typedef stack<char> STC;
typedef vector<STC> VSTC;
int main()
{
    string s;
    int TC = 1;
    while(cin >> s, s != "end"){
        VSTC vstc(1);
        set<char> setc;
        for(int i=0;i<(int)s.length();i++){
            setc.insert(s[i]);
            bool inserted = false;
            for(VSTC::iterator it = vstc.begin(); it != vstc.end(); it++){
                if((*it).size() == 0 || (int)(*it).top() >= (int)s[i]){
                    (*it).push(s[i]);
                    inserted = true;
                    break;
                }
            }
            if(!inserted){
                //add new stack
                STC stc;
                stc.push(s[i]);
                vstc.push_back(stc);
            }
        }
        int answer = 0;
        if(vstc.size() > setc.size())
            answer = setc.size();
        else
            answer = vstc.size();
        cout << "Case " << TC << ": " << answer << endl;
        TC++;
    }
}
