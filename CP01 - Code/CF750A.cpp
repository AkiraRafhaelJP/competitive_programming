#include <iostream>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K; 
    int time = 240 - K;
    int i=1, problem = 0;
    for(i=1;i<=N; i++){
        if(i*5 <= time){
            time -= i*5;
            problem++;
        }else{
            break;
        }
    }
    cout << problem << endl;
}


