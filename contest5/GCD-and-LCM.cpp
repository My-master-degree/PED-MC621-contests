#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
  int a, 
      b, 
      index = 0, 
      d,
      primesDiv = 0;
  ll pf, 
     j;
  vector<int> primes;
  scanf("%d%d", &a, &b);
  d = b/a;
  if (b%a == 0 && d > 1){
    //get prime numbers
    bool _primes[d + 1];
    memset(_primes, true, sizeof(_primes));
    _primes[0] = _primes[1] = false;
    for (pf = 2; pf <= d; pf++)
      if (_primes[pf]){
        for (j = pf * pf; j <= d; j += pf)
          _primes[j] = false;
        primes.push_back(pf);
      }
    //get prime factors
    for (pf = primes[index]; pf * pf <= d; pf = primes[++index])
      if (d%pf == 0){
        primesDiv++;
        for (; d%pf == 0; d /= pf);
      }
    if (d > 1)
      primesDiv++;
    if (primesDiv > 0)
      printf("%d", 1<<primesDiv);
    return 0;
  }
  printf("0");
  return 0;
}
