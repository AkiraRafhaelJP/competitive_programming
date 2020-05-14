#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

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
	int largestSet(){
		int Max = 0;
		for(int i=0;i<setSizes.size();i++){
			if(Max < setSizes[i]){
				Max = setSizes[i];
			}
		}
		return Max;
	}

};

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int N, M;
		scanf("%d %d", &N, &M);
		UFDS UF(N);

		int A, B;
		for(int i=0;i<M;i++){
			scanf("%d %d", &A, &B);
			UF.unionSet(A-1, B-1);
		}
		printf("%d\n", UF.largestSet());
	}
	return 0;
}
