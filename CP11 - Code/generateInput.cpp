#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int writeFile () 
{
  srand (time(NULL));

  
  
  ofstream myfile;
  myfile.open ("input.txt");
  int N = 100;
  for(int i=0;i<N; i++){
  	for(int j=0;j<N; j++){
  		int x = rand() % 2;
  		myfile << x << " ";
    }	
    myfile << endl;
  }
  myfile.close();
  return 0;
}

int main()
{
    writeFile();
}
