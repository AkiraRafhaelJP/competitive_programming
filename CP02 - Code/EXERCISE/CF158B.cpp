// https://codeforces.com/problemset/problem/158/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
int main(){
    int N; 
    cin >> N;
    vector<int> data(5, 0);
    int taxi = 0;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        data[x]++;
    }
    taxi += data[4];
    taxi += data[3];
    data[1] = max(0, data[3]-data[1]);

    taxi += data[2]/2;
    if(data[2]%2 == 1){
        taxi += 1;
        if(data[1] >= 2)
            data[1] -= 2;
        else
            data[1] = 0;
    }
    
    
    taxi += data[1] / 4;
    if(data[1] % 4 != 0)
        taxi += 1;
    cout << taxi << endl;
}
