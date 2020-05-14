#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, double> id; 
typedef pair<double, int> di; 
typedef vector<id> vid; 

vector<vid> adjList;
vector<int> visited;

double distance(dd a, dd b){
	return sqrt( (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

int main(){
	int tc;
	int blank = false;
	cin >> tc;
	while(tc--){
	    
		string s;
		getline(cin, s);
		cin.ignore();

		int n;
		cin >> n;
		vector< dd > nodes; 
		for(int i=0;i<n;i++){
			double a, b;
			cin >> a >> b;
			nodes.push_back( make_pair(a, b) );
		}
        adjList.clear();
		adjList.resize(n);
		visited.resize(n);
		double mst_cost = 0;

		fill(visited.begin(), visited.end(), 0);
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				dd A = nodes[i];
				dd B = nodes[j];
				adjList[i].push_back( make_pair(j, distance(A, B) ) );
				adjList[j].push_back( make_pair(i, distance(A, B) ) );
			}
		}

		priority_queue<di, vector<di>, greater<di> > pq;

		//choose a node
		visited[0] = 1;
		for(vid::iterator it = adjList[0].begin(); it != adjList[0].end(); it++){
			pq.push( make_pair( (*it).second, (*it).first ) );
		}

		while(!pq.empty()){
			di front = pq.top(); pq.pop();
			if(!visited[front.second]){
			    visited[front.second] = 1;
				mst_cost += front.first;
				//cout << "cost:" << mst_cost << endl;
				int node = front.second;
				for(vid::iterator it = adjList[node].begin(); it != adjList[node].end(); it++){
					pq.push( make_pair( (*it).second, (*it).first ) );
				}
			}
		}
        if(blank == 0){
            blank = 1;
        }else{
            printf("\n");
        }
		printf("%.2f\n", mst_cost);
	}
	return 0;
}