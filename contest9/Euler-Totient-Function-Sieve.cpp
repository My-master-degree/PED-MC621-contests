#include<bits/stdc++.h>

#define MAX 10000001

typedef long long ll;

using namespace std;

int main(){
  int index;
  ll pf, 
      j,
      phi,
      a,
      b,
      n;
  vector<int> primes;
  bitset<MAX> _primes;
  _primes.set();
  scanf("%lld %lld", &a, &b);
  if (b < 4){
    primes.push_back(2);
  }else{
    //sieve
    for (pf = 2; pf <= b / pf; pf++)
      if (_primes[pf]){
        for (j = pf * pf; j <= b/j; j += pf){
          _primes[j] = 0;
        }
        primes.push_back(pf);
      }
  }

  //euler
  for (j = a; j <= b; j++){
    phi = j;
    n = j;
    for (pf = primes[index = 0]; pf * pf <= n;){
      if (n%pf == 0) 
        phi -= phi/pf;
      while (n%pf == 0)
        n /= pf;
      index++;
      if (index < primes.size())
        pf = primes[index];
      else
        break;
    }
    ll r = n != 1 ? phi - 1 : phi;
//    if (r <= 0)
//      printf("Whoops in %lld\n", j);
    if (n != 1)
      phi -= phi/n;
    printf("%lld\n", phi);
  }
  return 0;
}
