#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
int map[1000][1000];
int memo[1000][1000];
int N;

int solve(int i, int j){
	if(i == N && j == N) return memo[i][j] = map[i][j];
	if(memo[i][j] != -1) return memo[i][j];
	int right = 0, down = 0; 
	if(j < N) right = map[i][j] + solve(i  , j+1);
	if(i < N) down = map[i][j] + solve(i+1, j  );

	return memo[i][j] = max(right, down);
}

int main(){
	memset(memo, -1, sizeof memo);
	ifstream myfile;
	N = 100;
	myfile.open("input.txt");
	  if (myfile.is_open())
	  {

	    for(int i=0;i<N;i++){
	   		for(int j=0;j<N;j++){
	   			int x;
	   			myfile >> x;
	   			map[i][j] = x;
	    	} 	
	    }
	    myfile.close();
	  }

	cout << solve(0,0) << endl;
	return 0;
}