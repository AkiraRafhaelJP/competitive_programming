#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void computeLPSArray(string W, int M, int* lps) 
{ 
	int len = 0; 
	lps[0] = 0; 

	int i = 1; 
	while (i < M) { 
		if (W[i] == W[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else 
		{ 
			if (len != 0) { 
				len = lps[len - 1]; 
			} 
			else 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
	// for(int i=0;i<M;i++){
	// 	cout << lps[i]; 
	// }
	// cout << endl;
} 

void KMPSearch(string W, string S) 
{ 
	int M = W.length(); 
	int N = S.length();
	int lps[M]; 

	computeLPSArray(W, M, lps); 

	int i = 0, j = 0;
	while (i < N) { 
		if (W[j] == S[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			printf("Found Wtern at index %d \n", i - j); 
			j = lps[j - 1]; 
		} 
		else if (i < N && W[j] != S[i]) { 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 



// Driver program to test above function 
int main() 
{ 
	string S = "ABABDABACDABABCABAB"; 
	string W = "ABABCABAB"; 
	KMPSearch(W, S); 
	return 0; 
} 
