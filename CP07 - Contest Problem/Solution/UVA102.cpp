#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int first = 0;
	while(cin >> first){
        long long data[4][4] = {};
		data[0][0] = first;
		cin >> data[0][1] >> data[0][2];
		cin >> data[1][0] >> data[1][1] >> data[1][2];
		cin >> data[2][0] >> data[2][1] >> data[2][2];
        
        int sum[3] = {};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                sum[i] += data[j][i];
            }
        }
        
        string s = "BGC";
		int permut[] = {0, 1, 2};
        long long minCost = 100000000000;
        string pos = "";
		do{
            string tmpPos = "";
            long long tmpCost = 0;

            for(int i=0;i<3;i++){
                tmpPos += s[ permut[i] ];
                tmpCost += sum[ permut[i] ] - data[i][ permut[i] ];
            }
            if(tmpCost < minCost){
                    minCost = tmpCost;
                    pos = tmpPos;
            }else if(tmpCost == minCost && minCost != 0){
                if(tmpPos < pos){
                    pos = tmpPos;
                }
            }
                
		}while(next_permutation(permut, permut + 3));

		cout << pos << " " << minCost << endl;

	}
	


}