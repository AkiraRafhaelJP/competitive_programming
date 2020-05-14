#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

#define UNVISITED -1

using namespace std;


typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;


int dfsRoot, dfsNumberCounter;
vvii AdjList;
vi dfs_low, dfs_num, dfs_bridge;

void AP(int u, int p){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;

	for(int j=0;j<(int)AdjList[u].size(); j++){
		ii v = AdjList[u][j];
		if(dfs_num[v.first] == UNVISITED){
			AP(v.first, u);
			if(dfs_low[v.first] > dfs_num[u]){
				dfs_bridge[v.first]++;
				dfs_bridge[u]++;
			}
			dfs_low[u] = min(dfs_low[v.first], dfs_low[u]);
		}else if(v.first != p){
			dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
		}
	}
}

bool cmp(ii A, ii B){
	return A.second > B.second || (A.second == B.second && A.first < B.first); 
}

int main(){
	int N, M; 
	int a, b;
	bool first = true;
	while(scanf("%d %d", &N, &M), N != 0 || M != 0){
		if(!first) printf("\n");
		else first = false;

		AdjList.clear();
		AdjList.resize(N);

		while(scanf("%d %d", &a, &b), a != -1 && b != -1){
			AdjList[a].push_back( ii(b, 1) ); 
			AdjList[b].push_back( ii(a, 1) ); 
		}
	 
		dfsNumberCounter = 0; dfs_num.assign(N, UNVISITED); 
		dfs_low.assign(N, 0); 
		dfs_bridge.assign(N, 0);


		AP(0, -1);
		vii station;
		for(int i=0;i<N;i++){
			if(dfs_bridge[i] < AdjList[i].size())
				station.push_back(  ii(i , dfs_bridge[i] + 1) );
			else
				station.push_back(  ii(i , dfs_bridge[i]) );
		}
		sort(station.begin(), station.end(), cmp);
		for(int i=0;i< M;i++){
			printf("%d %d\n",station[i].first,station[i].second);
		}
			
	}
	
	

	return 0;

}