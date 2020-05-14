#include <iostream>
#include <algorithm>
#include <vector> 
#include <stack> 

using namespace std;
typedef pair<int, int> ii;
using namespace std;

#define RIGHT 1
#define DOWN 2

int map[6][6] = {{0, 1, 0, 0, 0, 1}, 
				 {1, 1, 1, 0, 0, 1}, 	
				 {1, 0, 1, 0, 1, 1}, 	
				 {1, 1, 0, 1, 1, 0}, 	
				 {1, 1, 0, 1, 1, 1}, 	
				 {0, 0, 1, 1, 0, 1}};

int memo[6][6];
int direction[6][6];

int solve(int i, int j){
	if(i == 5 && j == 5) return memo[i][j] = map[i][j];
	if(memo[i][j] != -1) return memo[i][j];
	int right = 0, down = 0; 
	if(j < 5) right = map[i][j] + solve(i  , j+1);
	if(i < 5) down = map[i][j] + solve(i+1, j  );

	if(right > down)
		direction[i][j] = RIGHT;
	else 
		direction[i][j] = DOWN;
	return memo[i][j] = max(right, down);
}

void show(int i, int j){
	if(i <= 5 && j <= 5){
		cout << i << "," << j << endl;
		if(direction[i][j] == RIGHT) show(i, j+1);
		else show(i+1, j);	
	}
	
}

int main(){
	//cout << solve(0,0) << endl;
	memset(memo, -1, sizeof memo);
	solve(0,0);
	show(0,0);
	return 0;
}