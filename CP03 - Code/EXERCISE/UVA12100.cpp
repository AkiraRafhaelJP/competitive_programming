#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef queue<ii> QII;
typedef map<int, int> MII;


int main()
{
    int TC;
    cin >> TC;
    while(TC--){
        int N, M, x;
        QII q;
        MII m;
        cin >> N >> M;
        for(int i=0;i<N;i++){
            cin >> x;
            if(m.find(x) != m.end())
                m[x]++;
            else
                m[x] = 1;
            
            if(i == M)
                q.push( make_pair(x, 1) );
            else
                q.push( make_pair(x, 0) );
        }
        int Max = 0;
        int res = 0;
        do{
            ii last = (*m.rbegin());
            Max = last.first;
            while(q.front().first != Max) {
                   q.push(q.front());
                   q.pop();
            }
 
            res++;
            if(q.front().second == 1)
                break;
            q.pop();
            m[Max]--;
            if(m[Max] == 0)
                m.erase(last.first);
            
        }while(q.size() > 0);
        cout << res << endl;
    }
}