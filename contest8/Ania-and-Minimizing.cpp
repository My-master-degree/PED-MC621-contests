#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,
      k,
      i;
  scanf("%d%d", &n, &k);
  char S[n + 1];
  scanf("%s", S);
  if (k > 0 && n == 1)
    S[0] = '0';
  else if (S[0] > '1' && k > 0){
    k--;
    S[0] = '1';
  }
  for (i = 1; k > 0 && i < n; i++)
    if (S[i] > '0'){
      S[i] = '0';
      k--;
    }
  printf("%s", S);
}
