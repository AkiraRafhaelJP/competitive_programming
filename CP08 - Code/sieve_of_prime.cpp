#include <bitset>
#include <iostream>
#include <cstdio>

using namespace std;
typedef vector<int> vi;
typedef long long ll;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set(); // all 1
	bs[0] = bs[1] = 0;
	for(ll i=2; i<= _sieve_size; i++) if(bs[i]){
		for(ll j=i*i; j<= _sieve_size; j+= i) bs[j] = 0;
		primes.push_back( (int)i);
	}
}

bool isPrime(ll N){
	if(N <= _sieve_size) return bs[N];
	for(int i=0; i< (int) primes.size(); i++){
		if( N % primes[i] == 0) return false;
	}
	return true;
}

int main(){
	sieve(10000000);
	printf("%d\n", isPrime(2147483647));
	return 0;
}