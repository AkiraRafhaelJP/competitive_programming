#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n, d, r;
	while(cin >> n >> d >> r, n != 0 && d!= 0 && r!=0 ){
		vector<int> day, night; 
		int D, N;
		for(int i=0;i<n;i++){
			cin >> D;
			day.push_back(D);
			
		}

		for(int i=0;i<n;i++){
			cin >> N;
			night.push_back(N);
			
		}

		sort(day.begin(), day.end());
		sort(night.begin(), night.end(), greater<int>());
        
		int over = 0;
		for(int i=0;i<n;i++){    
            int tmp = (day[i] + night[i]);
            if(tmp > d){
                over += tmp-d;
            }
		}

		cout << over * r << endl;
	}

}