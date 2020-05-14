#include <cstdio>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;


int main(){
	int grid[4][5] = {{1, 1, 1, 1, 1},
					  {0, 0, 0, 0, 0},
					  {1, 1, 0, 1, 1},
					  {0, 1, 0, 1, 0}};
	
	ii pacman = ii(2, 0);
	const int UP_MOST = 0;
	const int DOWN_MOST = 3;
	const int LEFT_MOST = 0;
	const int RIGHT_MOST = 4;
	// init position
	cout << pacman.first << " " << pacman.second << endl;

	// move right
	while(pacman.second != RIGHT_MOST && 
		grid[ pacman.first ][ pacman.second + 1 ] != 0){
		if(grid[ pacman.first ][ pacman.second + 1 ] == 1 )
			pacman.second += 1;
	}
	cout << pacman.first << " " << pacman.second << endl;

	return 0;					
}