#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int t, N, S, Q; 
    cin >> t;
    while(t--){
        // INPUT
        cin >> N >> S >> Q;
        int total = 0;
        vector< queue<int> > VQ(N);
        for(int i=0;i<N;i++){
            int n; cin >> n;
            total+=n;
            queue<int> tmp;
            for(int j=0;j<n;j++){
                int x; cin >> x;
                tmp.push(x-1);
            }
            VQ[i] = tmp;
        }
        
        stack<int> C;
        int cost = 0;
        // PROCESS
        int pos = 0;
        while(total){
            // unloading
            while(C.size() != 0 && (VQ[pos].size() < Q || C.top() == pos) ){
                if(C.top() == pos){
                    C.pop(); cost++;
                    total--;
                }else{
                    VQ[pos].push(C.top()); C.pop(); cost++;    
                }
                
            }
            // loading
            while(C.size() < S && VQ[pos].size() != 0){
                C.push( VQ[pos].front() ); VQ[pos].pop(); cost++;
            }            
            // move
            pos = (pos + 1) % N;
            if(total > 0)
                cost += 2;
        }
        
        cout << cost << endl;
    }
}