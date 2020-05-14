#include <iostream>
using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b, a!=-1 && b!=-1){
        if(b < a){
            int tmp = a;
            a = b;
            b = tmp;
        }
        if( (a + 100 - b) > (b - a) ){
            cout << b - a << endl;
        }else{
            cout << a + 100 - b << endl;
        }
    }
}