#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int T; 
	cin >> T;
	while(T--){
		int A, B, C;
		cin >> A >> B >> C;
		bool sol = false;
		int x, y, z;

		for(x = -22; x <= 22 && !sol; x++) if(x*x <= C){
			for(y = -100; y <= 100 && !sol; y++) if(y!=x && x*x + y*y <= C){
				for(z = -100; z <= 100 && !sol; z++){
					if(x!=y && y!=z && x!=z && x+y+z == A && x*y*z == B && x*x+y*y+z*z == C){
						if(!sol){
							printf("%d %d %d\n", x, y, z);
							sol = true;
						}
					}
				}
			}
		}



		if(!sol){
			printf("No solution.\n");
		}

	}

}