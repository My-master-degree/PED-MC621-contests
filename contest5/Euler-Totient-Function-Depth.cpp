#include<bits/stdc++.h>

#define MAX 1000001 
#define MAX_K 20

typedef long long ll;

using namespace std;

  int phi[MAX], 
      seq_size[MAX];
  int rel[MAX_K][MAX];

int main(){
  int T, 
      m, 
      n,
      k,
      pf,
      j;
  for (pf = 0; pf < MAX; pf++)
    phi[pf] = pf;
  for (pf = 2; pf < MAX; pf++){
    if (phi[pf] == pf){
      for (j = pf + pf; j < MAX; j += pf)
        phi[j] -= phi[j]/pf;
      phi[pf]--;
    }
    seq_size[pf] = seq_size[phi[pf]] + 1;
    if (seq_size[pf] < MAX_K)
      rel[seq_size[pf]][pf] = 1;
  }

  rel[0][1] = 1;
  for (k = 0; k < MAX_K; k++)
    for (pf = 1; pf < MAX; pf++)
      rel[k][pf] += rel[k][pf - 1];
  scanf("%d", &T);
  while (T--){
    scanf("%d %d %d", &m, &n, &k);
    printf("%d\n", rel[k][n] - rel[k][m - 1]);
  }


//  for (k = 1; k <= MAX_K; k++){
//    printf("%d:", k);
//    for (pf = 1; pf <= MAX; pf++){
//      printf(" %d", rel[k][pf]);
//    }
//    printf("\n");
//  }
  return 0;
}
