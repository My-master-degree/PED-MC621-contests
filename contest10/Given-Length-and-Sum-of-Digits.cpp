#include<bits/stdc++.h>

using namespace std;

int main(){
  int m, s, MAX = 0, MIN = 1, i, j;
  cin>>m>>s;
  for (i = 1; i <= m; i++){
    MAX = MAX * 10;
    MAX += 9;
  }
  for (i = 1; i < m; i++)
    MIN *= 10;
  for (i = MIN; i <= MAX; i++){
    j = i;
    if (j%10 + (j /= 10)%10 + j/10 == s){
      printf("%d ", i);
      break;
    }
  }
  for (i = MAX; i >= MIN; i--){
    j = i;
    if (j%10 + (j /= 10)%10 + j/10 == s){
      printf("%d", i);
      return 0;
    }
  }
  printf("-1 -1");
  return 0;
}
