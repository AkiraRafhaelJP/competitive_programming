#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int k;
    while(cin >> k){
        int jumlah = 0;
        for(int i=k+1;i<=2*k; i++){
                if( (i*k)%(i-k) == 0 ){
                    jumlah++;
                }
        }
        cout << jumlah << endl;
        for(int i=k+1;i<=2*k; i++){
                if( (i*k)%(i-k) == 0 ){
                    printf("1/%d = 1/%d + 1/%d\n", k, (i*k)/(i-k), i);
                }
        }
    }
}