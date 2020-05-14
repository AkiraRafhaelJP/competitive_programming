#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int map[6][6] = {{0, 1, 0, 0, 0, 1}, 
				 {1, 1, 1, 0, 0, 1}, 	
				 {1, 0, 1, 0, 1, 1}, 	
				 {1, 1, 0, 1, 1, 0}, 	
				 {1, 1, 0, 1, 1, 1}, 	
				 {0, 0, 1, 1, 0, 1}};

int memo[6][6];

int solve(int i, int j){
	if(i == 5 && j == 5) return memo[i][j] = map[i][j];
	if(memo[i][j] != -1) return memo[i][j];
	int right = 0, down = 0; 
	if(j < 5) right = map[i][j] + solve(i  , j+1);
	if(i < 5) down = map[i][j] + solve(i+1, j  );

	return memo[i][j] = max(right, down);
}

int main(){
	memset(memo, -1, sizeof memo);
	cout << solve(0,0) << endl;
	return 0;
}