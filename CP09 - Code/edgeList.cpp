#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;


int main(){
	vector< pair<int, ii> > edgeList;
	
	//edge 1
	edgeList.push_back( make_pair(1, ii(0, 1) ) );
	edgeList.push_back( make_pair(1, ii(1, 0) ) );

	edgeList.push_back( make_pair(1, ii(1, 2) ) );
	edgeList.push_back( make_pair(1, ii(2, 1) ) );

	edgeList.push_back( make_pair(1, ii(1, 3) ) );
	edgeList.push_back( make_pair(1, ii(3, 1) ) );

	edgeList.push_back( make_pair(1, ii(3, 4) ) );
	edgeList.push_back( make_pair(1, ii(4, 3) ) );

	edgeList.push_back( make_pair(1, ii(4, 5) ) );
	edgeList.push_back( make_pair(1, ii(5, 4) ) );

	edgeList.push_back( make_pair(1, ii(4, 6) ) );
	edgeList.push_back( make_pair(1, ii(6, 4) ) );
	
	vector< pair<int, ii> >::iterator it; 
	for(it = edgeList.begin(); it != edgeList.end(); it++){
		cout << (*it).second.first << " " << (*it).second.second << endl;
	}

	return 0;					
}