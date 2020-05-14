#include <cstdio>
#include <set> 

using namespace std;

int main(){
    int n;
    while(scanf("%d", &n), n != 0){
        multiset<int> si;
        long long cost = 0;
        for(int i=0;i<n;i++){
            int x, data;
            scanf("%d", &x);
            for(int j=0;j<x;j++){
                scanf("%d", &data);
                si.insert(data);
            }
            long long Min = (*si.begin());
            long long Max = (*si.rbegin());
            cost += Max - Min; 
            si.erase(si.find(Max));
            si.erase(si.find(Min));  
        }
        printf("%d\n",cost);
    }
}