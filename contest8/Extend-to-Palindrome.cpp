#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

void swap (char * a, char * b);
int reverse (char * S, int N);
int getLongestLPPSSize (char * __S, int N);

int main(){
  char S[MAX], 
       _S[MAX],
       __S[2 * MAX];
  int N,
      i,
      lppss;
  while(scanf("%s", S) == 1){
    N = strlen(S);
    if (N){
      strcpy(_S, S);
      reverse(_S, N);
      strcpy(__S, _S);
      strcat(__S, "#");
      strcat(__S, S);
      lppss = getLongestLPPSSize(__S, 2 * N + 1);
      printf("%s", S);
      for (i = N - lppss - 1; i >= 0 ; i--){
        printf("%c", S[i]);
      }
      printf("\n");
    }else
      break;
  }
  return 0; 
}

void swap(char * a, char * b){
  if (*a != *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
  }
}

int reverse(char * S, int N){
  for (int i = 0; i <= N/2; i++)
    swap(&S[i], &S[N - i - 1]);
}

int getLongestLPPSSize (char * __S, int N){
  int i = 0,
      j = -1;
  int lpps[N + 1];
  lpps[0] = -1;
  while (i < N){
    while (j >= 0 && __S[i] != __S[j])
      j = lpps[j];
    i++;
    j++;
    lpps[i] = j;
  }
  return lpps[N];
}
