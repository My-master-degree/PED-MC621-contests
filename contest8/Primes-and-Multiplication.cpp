#include<bits/stdc++.h>

#define MOD 1000000007
#define MAX 31622
#define vi vector<int>

typedef unsigned long long ull;

using namespace std;

ull pow(ull b, ull e, ull m);
ull _h(ull n, ull p);

int main(){
  int x,
      i;
  ull n, 
     j,
     r;
  vi::iterator it;
  cin>>x>>n;
  //sieve
  bitset<MAX + 1> bs;
  vi primes;
  bs.set();
  bs[0] = bs[1] = 0;
  for (i = 0; i * i <= x; i ++)
    if (bs[i]){
      for (j = i * i; j * j <= x; j += i)
        bs[j] = 0;
      if (x%i == 0)
        primes.push_back(i);
    }
  if (primes.size() == 0)
    primes.push_back(x);
  //
  r = 1;
  for (it = primes.begin(); it != primes.end(); it++){
    cout<<*it<<"^"<<_h(n, *it)<<" mod MOD ="<<pow(*it, _h(n, *it), MOD)<<endl;
    r = (r * pow(*it, _h(n, *it), MOD))%MOD; 
  }
  cout<<r;

}

ull _h(ull n, ull p){
  printf("_h\n");
  ull m = p,
     r = 0;
  while (n/m > 0){
    r += n/m;
    m *= p;

 if(n/p<m) break;
    cout<<m<<endl;
  }
  return r;
}

ull pow(ull b, ull e, ull m){
  ull r = 1;
  if (e){
    r = pow(b, e/2, m);
    r =(r * r)%m;
    if (e&1)
      r = (r * (b%m))%m;
  }
  return r%m;
}
