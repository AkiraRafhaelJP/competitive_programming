#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;


int main(){
	vector<vii> adjList(7);
	
	//edge 1
	adjList[0].push_back( ii(1, 1) );

	adjList[1].push_back( ii(0, 1) );
	adjList[1].push_back( ii(2, 1) );
	adjList[1].push_back( ii(3, 1) );

	adjList[2].push_back( ii(1, 1) );	
	
	adjList[3].push_back( ii(1, 1) );
	adjList[3].push_back( ii(4, 1) );		

	adjList[4].push_back( ii(3, 1) );
	adjList[4].push_back( ii(5, 1) );
	adjList[4].push_back( ii(6, 1) );

	adjList[5].push_back( ii(4, 1) );

	adjList[6].push_back( ii(4, 1) );

	for(int i=0;i<7;i++){
		cout << i << ": "; 
		vii::iterator it; 
		for(it = adjList[i].begin(); it != adjList[i].end(); it++ ){
			cout << (*it).first << " ";
		}
		cout << endl;
	}

	return 0;					
}