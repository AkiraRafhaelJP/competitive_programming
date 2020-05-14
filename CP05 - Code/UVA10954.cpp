#include <cstdio>
#include <queue> 

using namespace std; 

int main(){
    int n;
    while(scanf("%d", &n), n!=0){
    	priority_queue<int> pq;
		long long sum = 0;
		int x, i; 
		for(i=0;i<n;i++){
			scanf("%d", &x);
			pq.push(-1 * x);
		}

		int a, b;
		while(!pq.empty()){
			a = pq.top(); pq.pop();
			b = pq.top(); pq.pop();
			sum += -1LL * (a + b);
			if(pq.empty()){
				break;
			}
			pq.push(a + b);

		}

		printf("%lld\n", sum);
    }
	

}