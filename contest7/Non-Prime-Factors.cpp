#include<bits/stdc++.h>

#define MAX 2000010
#define  vi vector<int>

typedef long long ll;

using namespace std;

map<int, int> m;
bitset<MAX> _primes;

int rel[MAX];

int npf(int N){
  int primes_count = 0, 
      div_count = 1, 
      exp;
  for (ll i = 2; i * i <= N; i++){
    if (_primes[i]){
      for (ll j = i * i; j * j <= N; j += i)
        _primes[j] = 0;
      if (N%i == 0){
        primes_count++;
        for (exp = 0; N%i == 0; exp++)
          N /= i;
        div_count *= (exp + 1);
      }
    }
  }
  if (N != 1){
    div_count *= 2;
    primes_count++;
  }
  return div_count - primes_count;


}

int main(){
  int q, i, s;
  _primes.set();
  memset(rel, -1, sizeof rel);
  map<int, int>::iterator it;
  scanf("%d", &q);
  while(q--){
    scanf("%d", &i);
//    iit = m.find(i);
//    if (it != m.end())
//      printf("%d\n", it->second);
    if (rel[i] >= 0)
      printf("%d\n", rel[i]);
    else{
//      s = npf(i);
//      m[i] = s;
      rel[i] = npf(i);
      printf("%d\n", rel[i]);
    }
  }
}
