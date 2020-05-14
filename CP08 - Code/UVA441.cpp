#include <iostream>
#include <cstdio>
#include <vector>
using namespace std; 

int main(){
    int k;
    bool flag = false;
	while(cin >> k, k != 0){
        if(flag) cout << endl;
		vector<int> D;
		for(int i=0;i<k;i++){
			int x; 
			cin >> x;
			D.push_back(x);
		}	

		for(int a=0; a<k-5; a++){
			for(int b=a+1; b<k-4; b++){
				for(int c=b+1; c<k-3; c++){
					for(int d=c+1; d<k-2; d++){
						for(int e=d+1; e<k-1; e++){
							for(int f=e+1; f<k; f++){
								printf("%d %d %d %d %d %d\n", D[a], D[b], D[c], D[d], D[e], D[f]);
							}
						}
					}
				}
			}		
		}
        flag = true;
	}
	
	
	return 0;
}