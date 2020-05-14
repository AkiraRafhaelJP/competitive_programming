#include <iostream>
#include <cstdio>
#include <vector>

#define UNVISITED -1

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;


vi dfs_low, dfs_num, dfs_parent, articulation_vertex;
int dfsNumberCounter, rootChildren, dfsRoot;

void APB(int u, vvii AdjList){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for(int j=0;j<(int)AdjList[u].size();j++){
		ii v = AdjList[u][j];
		if(dfs_num[v.first] == UNVISITED){
			dfs_parent[v.first] = u;
			if( u == dfsRoot ) rootChildren++;

			APB(v.first, AdjList);

			if(dfs_low[v.first] >= dfs_num[u])
				articulation_vertex[u] = true;
			dfs_low[u] = min(dfs_low[v.first], dfs_low[u]);
		}else if(v.first != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[v.first], dfs_low[u]);
		}
	}
}

int main(){
	int V, E; 
	int a, b;

	cin >> V >> E;
	vvii AdjList(V);

	for(int i=0;i<E;i++){
		cin >> a >> b;
		AdjList[a].push_back( ii(b, 1) );
	}

	dfsNumberCounter = 0; dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0);
	dfs_parent.assign(V, 0); articulation_vertex.assign(V,0);


	dfsRoot = 0; rootChildren = 0; APB(dfsRoot, AdjList);
	articulation_vertex[dfsRoot] = (rootChildren > 1);
	for(int i=0;i<V;i++){
		if(articulation_vertex[i])
			printf("Vertex %d\n", i);
	}
	return 0;
}