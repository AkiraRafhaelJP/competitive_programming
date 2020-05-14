// https://codeforces.com/problemset/problem/405/A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
int main(){
    int N; 
    cin >> N;
    vector<int> data;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        data.push_back(x);
    }
    sort(data.begin(), data.end());
    for(vi::iterator it = data.begin(); it != data.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;
}
