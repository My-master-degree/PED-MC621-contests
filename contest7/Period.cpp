#include<bits/stdc++.h>

#define MAX 1000001

using namespace std;

void kmpPreprocess (char * T, int * lpps, int N);

int main(){
  int T, 
      N,
      len,
      k,
      i;
  char S[MAX];
  int lpps[MAX];
  //read input
  scanf("%d", &T);
  for (i = 1; i <= T; i++){
    scanf("%d", &N);
    getchar();
    scanf("%[^\n]", S);
    getchar();
    len = strlen(S);
    kmpPreprocess(S, lpps, len);
    printf("Test case #%d\n", i);
    for (int i = 1; i <= len; i++){
      k =  i % (i - lpps[i]) == 0 ? i / (i - lpps[i]) : 1;
      if (k > 1)
        printf("%d %d\n", i, k);
    }
    printf("\n");
  }
}

void kmpPreprocess (char * T, int * lpps, int N){
  int i = 0,
      j = -1;
  lpps[0] = -1;
  while (i < N){
    while (j >= 0 && T[i] != T[j])
      j = lpps[j];
    i++;
    j++;
    lpps[i] = j;
  }
}

