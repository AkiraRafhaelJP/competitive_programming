#include <iostream>
#include <algorithm> 
#include <vector> 

using namespace std;

typedef vector<int> vi;

int main(){
	int tc = 1,n;
	while(cin >> n, n >= 0){
		vi create(13), need(13);
		int x;
		create[0] =  n;
		need[0] = 0;
		for(int i=1;i<=12;i++){
			cin >> x;
			create[i] = create[i-1] + x;
		}
		for(int i=1;i<=12;i++){
			cin >> x;
			need[i] = x;
			
		}
		cout << "Case " << tc++ << ":" << endl;
		int used = 0;
		for(int i=1;i<=12;i++){
			if(need[i] <= create[i-1] - used){
				cout << "No problem! :D" << endl;
				used += need[i];
			}else{
				cout << "No problem. :(" << endl;
			}
		}

	}
	return 0;
}