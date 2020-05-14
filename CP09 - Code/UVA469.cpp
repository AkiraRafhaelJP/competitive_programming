#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

typedef pair<int, int> ii; 
typedef vector<int> vi;
typedef vector<ii> vii; 

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};


int bfs(ii P, vector<string> data){
	queue<ii> q; 
	q.push(P);
	int area = 0; 
	
	while(!q.empty()){
		ii p = q.front(); q.pop();
		area++;
        data[ p.first ][ p.second ] = 'L';
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				int r = p.first + dr[i];
				int c = p.second + dc[j];
                
                if(r >= 0 && r < data.size() && c >= 0 && c < data[0].length() ){
                     if( data[ r ][ c  ]  == 'W' ){
                        q.push( ii(r, c) );
                     }
                }
				
			}
		}		
	}	
    return area;
}


int main(){
	int T; 
	string input;
	cin >> T; 
	cin.ignore();
	getline(cin, input);
	vector<string> data;
	vii L;
	while(T--){
		
		while(true){	
			istringstream iss;
			string line; 
			getline(cin, line);
			if(line.length() == 0 ){
				break;
			}
			if(isdigit(line[0])){
				iss.str(line);
				int A, B;
				iss >> A;
				iss >> B;
				L.push_back( ii(A, B));		
			}else{
				data.push_back(line);		
			}
			
		}
//		for(int i=0;i<data.size();i++){
//			cout << data << endl;
//		}
		vii::iterator it;
		for(it = L.begin(); it != L.end(); it++){
			cout << bfs( (*it), data ) << endl;
		}		
	}
}
