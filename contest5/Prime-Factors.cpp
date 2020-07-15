#include<bits/stdc++.h>

#define MAX 100000
#define MAX_PRIMES 81


typedef long long ll;

using namespace std;

int main(){
  list<int> primes[MAX + 1];
  list<int>::iterator it;
  int index, pf, j;

  for (pf = 2; pf <= MAX; pf++){
    if (primes[pf].empty()){
      for (j = pf; j <= MAX; j += pf)
        primes[j].push_back(pf);
    }
  }
  for (j = 2; j < MAX + 1; j++){
    printf("%d:", j);
    for (it = primes[j].begin(); it != primes[j].end(); ++it){
      printf(" %d", *it);
    }
    printf("\n");
  }
  return 0;
}
