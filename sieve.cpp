// Sieve and SieveForPrimeFactorisation are tow preprocessing functions they may be called in main in case of mutlitple testcases ;
const int MX=10000000;
int sieve[MX+1]; // for prime factorization in O(MXlog(MX));
int prime[MX+1]; // for getting primes up to MX;
void Sieve(){
	prime[1] = prime[0] = 0;
	prime[2]=1;
	for(int i=3; i<=MX; i+=2){
		prime[i] = 1;
	}
	for(ll i=3; i<=MX; i++)
		if(prime[i])
			for(ll j = i*i; j<=MX; j = j + i)
				prime[j] = 0;

}
///////////////////////////////////////// prime factorization in O(Nlog(N))/////////////////////////////////////// 
/// dont forget to  call SieveForPrimeFactorisation  !!!!
void SieveForPrimeFactorisation(){ // marks x with its smallest prime factor ;
	for(int i=1; i<=MX; i++){
		sieve[i] = i;
	}
	for(ll i=2; i<=MX; i++)
		if(sieve[i]==i)
			for(ll j= i*i; j<=MX; j = j + i)
				if(sieve[j]==j)
					sieve[j] = i;
}


unordered_map<ll,ll> getFactorisation(ll x){
	unordered_map<ll,ll> ret;
	while(x!=1){
		ret[sieve[x]]++;
		x = x/sieve[x];
	}
	return ret;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
