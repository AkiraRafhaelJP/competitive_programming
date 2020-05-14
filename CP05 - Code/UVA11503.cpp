#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

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

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int F;
		cin >> F;
		int N = 0;
		vii list;
		map<string, int> mp;

		string A, B;
		for(int i=0;i<F;i++){
			cin >> A >> B;

			if( mp.find(A) == mp.end()) {
				N++;
				mp[A] = N;
			}
			if( mp.find(B) == mp.end()) {
				N++;
				mp[B] = N;
			}

			list.push_back( make_pair(mp[A], mp[B]) );
		}

		UFDS UF(N);
		vii::iterator it;
		for(it = list.begin(); it != list.end(); it++){
			UF.unionSet( (*it).first - 1, (*it).second - 1 );
			cout << UF.setSize( (*it).first - 1 ) << endl;
		}
	}
	
	return 0;


}