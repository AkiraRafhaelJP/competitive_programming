#include <iostream>
#include <cstdio>
#include <set> 
#include <cstring>
#include <algorithm>

#define V 100
#define INF -1 
using namespace std;

int graph[101][101]; 
set<int> nodes;

void floydWarshall ()
{
    int i, j, k;

    for (k = 1; k <= V; k++)if(nodes.find(k) != nodes.end())
    {
        for (i = 1; i <= V; i++)if(nodes.find(i) != nodes.end())
        {
            for (j = 1; j <= V; j++)if(nodes.find(j) != nodes.end())
            {
                if(graph[i][k] != INF && graph[k][j] != INF){
                   if(graph[i][j] == INF)
                      graph[i][j] = graph[i][k] + graph[k][j];    
                   else if (graph[i][k] + graph[k][j] < graph[i][j])
                      graph[i][j] = graph[i][k] + graph[k][j];
                }
                
            }
        }
    }
}

double printSolution(){
  int counter = 0, i, j;
  double sum = 0;
  for (i = 1; i <= V; i++)if(nodes.find(i) != nodes.end())
  {
      for (j = 1; j <= V; j++)if(nodes.find(j) != nodes.end())
      {
          if(graph[i][j] != INF && i!=j){

              sum += (double) graph[i][j];
              counter++;  
          }
          
      }
  }
  return sum/counter;
}
 
int main()
{
    int A, B; 
    int T = 1;
    while(cin >> A >> B, A != 0 || B != 0){
        memset(graph, INF, (V+1)*(V+1)*sizeof(graph[0][0]));
        nodes.clear();
        for(int i=0;i<100;i++){
            graph[i][i] = 0;
        }
        nodes.insert(A);nodes.insert(B);

        graph[A][B] = 1;
        int C, D;
        while(cin >> C >> D, C != 0 && D != 0){
            graph[C][D] = 1;
            nodes.insert(C);nodes.insert(D);
        } 

        floydWarshall();  
        printf("Case %d: average length between pages = %.3F clicks\n", T++, printSolution());
    }
    return 0;
}