#include<bits/stdc++.h>
#define MAX 1000000007

using namespace std;

int main(){
  int h,
      w,
      i,
      j,
      k,
      C;
  scanf("%d%d", &h, &w);
  int r[h + 1],
      c[w + 1];
  bool M[h + 1][w + 1];
  //read data
  for (i = 1; i <= h; i++)
    scanf("%d", &r[i]);
  for (k = 1; k <= w; k++)
    scanf("%d", &c[k]);
  //check feability
  for (i = 1; i <= h; i++)
    if (r[i] + 1 <= w && c[r[i] + 1] >= i){
      printf("0");
      return 0;
    }
  for (j = 1; j <= w; j++)
    if (c[j] + 1 <= h && r[c[j] + 1] >= j){
      printf("0");
      return 0;
    }
  //build matrix
  for (i = 1; i <= h; i++)
    for (j = 1; j <= w; j++)
      M[i][j] = false;
  for (i = 1; i <= h; i++)
    for (j = 1; j <= r[i]; j++)
      M[i][j] = true;
  //count cases
  C = 1;
  for (i = 1; i <= h; i++){
    k = r[i] + 2;
    for (j = k; j <= w; j++)
      if (M[i][j] == 0 && i >= c[j] + 2){
        C = ((C%MAX) * 2)%MAX;
      }
  }
  printf("%d", C);
  return 0;
}
