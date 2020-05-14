#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; 
    while(cin >> n, n != 0){
        long long total = 0;
        map<int, int> data; 
        map<int, int>::iterator itMin, itMax;
        for(int i=0;i<n;i++){
            int k, x;
            cin >> k;
            for(int j=0;j<k;j++){
                cin >> x;
                data[x]++;
            }
            itMin = data.begin();
            itMax = --data.end();
            total+= (*itMax).first-(*itMin).first;
            if( (*itMax).second == 1  ) data.erase( itMax );
            else (*itMax).second-=1;
            if( (*itMin).second == 1  ) data.erase( itMin );
            else (*itMin).second-=1;
        }
        cout << total << endl;
    }
}