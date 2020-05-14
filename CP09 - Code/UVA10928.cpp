#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;


int main(){
	
	int T; 
	cin >> T; 
	
	while(T--){
		string input;
		int N;
		cin >> N; 
		int Min = 2000;
		cin.ignore();
		vector<vi> adjList(N);
		for(int i=0;i<N;i++){
			
			getline(cin, input);
	  		istringstream iss (input);
	  		int node;
	  		int numOfNode = 0;
	  	    while(iss >> node)
		    {
		      	adjList[i].push_back( node-1 );
		    	numOfNode++;
		    }

		    if(Min > numOfNode)
		    	Min = numOfNode;
		}

		bool first = true;
		for(int i=0;i<N;i++){
			if(adjList[i].size() == Min){
				if(first){
					first = false;
				}else{
					cout << " ";
				}
				cout << i+1;
			}


		}
		cout << endl;
		if(T!=0)
			getline(cin, input);
	}
}