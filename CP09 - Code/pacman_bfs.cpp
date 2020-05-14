#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int grid[5][5] = {{1, 1, 1, 1, 1},
		    {0, 0, 0, 1, 0},
		    {1, 1, 0, 1, 1},
		    {0, 1, 0, 1, 0},
		    {1, 1, 1, 1, 1}};
int visited[5][5];
ii pacman = ii(4, 0);
const int UP_MOST = 0;
const int DOWN_MOST = 4;
const int LEFT_MOST = 0;
const int RIGHT_MOST = 4;

void printMap(ii p){
	//system("clear");
	cout << "======" << endl;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(i == p.first && j == p.second){
				cout << "C";
			}else if(grid[i][j] == 0)
				cout << "#";
			else{
				if(visited[i][j] == 1)
					cout << " ";
				else 
					cout << ".";
			}
		}
		cout << endl;
		usleep(5000);
	}
}

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(ii pacman){
	queue<ii> q; 
	q.push(pacman); 
	while(!q.empty()){
		ii p = q.front(); q.pop();
		if( !(p.first < UP_MOST || p.first > DOWN_MOST || p.second < LEFT_MOST || p.second > RIGHT_MOST) && !visited[ p.first ][ p.second ] ){
			printMap(p);
			visited[ p.first ][ p.second ] = 1;
			for(int i=0;i<4;i++){
				if( grid[ p.first + dr[i] ][p.second + dc[i] ] == 1 ){
					q.push( ii(p.first + dr[i], p.second + dc[i]) );
				}
			}
		}	
	}
}

int main(){
	bfs(pacman);


	return 0;					
}