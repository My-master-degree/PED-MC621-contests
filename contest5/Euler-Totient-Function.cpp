#include<bits/stdc++.h>

#define MAX 1000001

typedef long long ll;

using namespace std;

int main(){
  int phis[MAX];
  int pf, 
      j,
      t,
      n;
  for (j = 0; j < MAX; j++)
    phis[j] = j;
  for (pf = 2; pf < MAX; pf++)
    if (phis[pf] == pf){
      for (j = pf + pf; j < MAX; j += pf)
        phis[j] -= phis[j]/pf;
      phis[pf]--;
    }
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    printf("%d\n", phis[n]);
  }
  return 0;
}
