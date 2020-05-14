#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string> 

using namespace std;
typedef pair<int, int> ii;

class UFDS {
private:
	vector<int> p, rank, setSizes;
	int numSets;
public:
	UFDS(int N) {
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
		setSizes.assign(N, 1);
	}
	int findSet(int i) {
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				setSizes[findSet(x)] += setSizes[findSet(y)];
				p[y] = x;
			} else {
				setSizes[findSet(y)] += setSizes[findSet(x)];
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
			numSets--;
		}
	}
	int setSize(int i) {
		return setSizes[findSet(i)];
	}
	int numDisjointSets() {
		return numSets;
	}
};


// kruskal

int countDistance(string A, string B){
	int total = 0;
	for(int i=0;i<4;i++){
		int a = (int) A[i];
		int b = (int) B[i];
		total += min(10-abs(a-b), abs(a-b));
	}
	return total;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
        cin >> N;
		vector<string> lock; 
		string input; 
        bool isZeroExist = false;
		lock.push_back("0000");
		for(int i=0;i<N;i++){
			cin >> input;
            if(input == "0000"){
                isZeroExist = true;
                continue;
            }
			lock.push_back(input);
		}


		// do kruskal
		int V = lock.size();
		
	    int u,v,w;
	    

		vector< pair<int, ii> > EdgeList; 
    
        if(!isZeroExist){
			for(int i = 1; i < V-1; i++){
				for(int j=i+1; j < V; j++){
					EdgeList.push_back( make_pair(countDistance(lock[i], lock[j]), ii(i,j)) );
				}
			}

				//choosing shortest from 0000
			pair<int, ii> candidate;
			int cost = 10000;
			for(int j=1;j<V;j++){
				int tmpcost = countDistance(lock[0], lock[j]);
				if(tmpcost < cost){
					cost = tmpcost;
					candidate = make_pair(tmpcost, ii(0, j));
				}
			}
			EdgeList.push_back(candidate);
        }else{
        	for(int i = 0; i < V-1; i++){
				for(int j=i+1; j < V; j++){
					EdgeList.push_back( make_pair(countDistance(lock[i], lock[j]), ii(i,j)) );
				}
			}
        }

		

		int E = EdgeList.size();
		sort(EdgeList.begin(), EdgeList.end());
	

		int mst_cost = 0;
		UFDS UF(V);

		for(int i=0; i<E; i++){
			pair<int, ii> front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}

		printf("%d\n", mst_cost);


	}


	return 0;


}