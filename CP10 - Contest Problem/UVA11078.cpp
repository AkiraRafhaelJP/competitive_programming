#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> v(n);
        int Max = 0, gap = -150000;
        for(int i=0;i<n;i++){
            cin >> v[i];
            if(i!=0){
                if(v[Max] - v[i] > gap && Max < i){
                    gap = v[Max] - v[i];
                }
                if(v[i-1] - v[i] > gap){
                    gap = v[i-1] - v[i];
                }
                if(v[i-1] > v[Max])
                    Max = i-1;
            }
            
        }
        cout << gap << endl;
    }
    
}