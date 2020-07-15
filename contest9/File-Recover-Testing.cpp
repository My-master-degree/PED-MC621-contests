#include<bits/stdc++.h>

#define MAX 1000000

using namespace std;

char S[MAX + 1];
int lpps[MAX + 1];
int M;

void kmpPreprocess(){
  int i = 0,
      j = -1;
  lpps[0] = -1;
  while (i < M){
    while (j >= 0 && S[i] != S[j])
      j = lpps[j];
    i++;
    j++;
    lpps[i] = j;
  }
}

int main(){
  int k;
  while (true) {    
    scanf("%d %s", &k, S);
    if (k == -1)
      break;
    getchar();
    M = strlen(S);
    if (k < M)
      printf("0\n");
    else{ 
      kmpPreprocess();
      k -= lpps[M];
      printf("%d\n", k/(M-lpps[M]));
    }

  }
  return 0;
}
