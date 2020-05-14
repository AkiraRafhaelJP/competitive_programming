#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main(){
	int n, m; 
	

	while(cin >> n >> m, n!=0 || m!= 0){
		vector<iii> C;
		vector<iii>::iterator it;
		for(int i=0;i<m;i++){
			int a, b, c;
			cin >> a >> b >> c;
			C.push_back( make_pair(ii(a, b), c) );

		}
		
		int sol = 0;		
		int p[8] = {0, 1, 2, 3, 4, 5, 6, 7};	
		do{
			bool allow = true;
			for(it = C.begin(); it != C.end(); it++){
				iii cons = (*it);
				int a = cons.first.first;
				int b = cons.first.second;
				int c = cons.second;

				if(c > 0){
					if( abs(p[a] - p[b]) > abs(c) ) {
						allow = false;
						break;
					}
				}else{
					if( abs(p[a] - p[b]) < abs(c) ) {
						allow = false;
						break;
					}
				}
			}
			if(allow == true) sol++;
		}while(next_permutation(p, p+n));
		cout << sol << endl;
	}

}