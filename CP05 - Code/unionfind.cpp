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
		cout << "union " << i << " " << j << endl;
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
	void printSets(){
		printf("index: \t\t");
		for(int i=0;i<p.size();i++){
			printf("%2d  ", i);
		}
		printf("\n");

		printf("parent: \t");
		for(int i=0;i<p.size();i++){
			printf("%2d  ", p[i]);
		}
		printf("\n");

		printf("rank: \t\t");
		for(int i=0;i<p.size();i++){
			printf("%2d  ", rank[i]);
		}
		printf("\n");

		printf("size: \t\t");
		for(int i=0;i<p.size();i++){
			printf("%2d  ", setSizes[i]);
		}
		printf("\n\n");
	}

};

int main(){
	int N = 10;
	UFDS uf(N);
	uf.printSets();

	uf.unionSet(0,4);
	uf.printSets();

	uf.unionSet(3,5);
	uf.printSets();

	uf.unionSet(3,4);
	uf.printSets();
	
	return 0;


}