#include <cstdio>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;


int main(){
	int adjMatrix[7][7] = {0};
	
	//edge 1
	adjMatrix[0][1] = adjMatrix[1][0] = 1;
	//edge 2
	adjMatrix[1][2] = adjMatrix[2][1] = 1;
	//edge 3
	adjMatrix[1][3] = adjMatrix[3][1] = 1;
	//edge 4
	adjMatrix[3][4] = adjMatrix[4][3] = 1;	
	//edge 5
	adjMatrix[4][5] = adjMatrix[5][4] = 1;
	//edge 6
	adjMatrix[4][6] = adjMatrix[6][4] = 1;	

	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;					
}