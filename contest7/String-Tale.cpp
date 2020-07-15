#include<bits/stdc++.h>

using namespace std;

void kmpPreprocess (char * T, int * lpps, int N);
int kmpSearch(char * _S, int n, char * T, int * lpps, int N);

int main(){
  int N, 
      _N,
      index;
  //read input
  scanf("%d", &N);
  _N = 2 * N;
  char S[N + 1],
      T[N + 1],
      _S[_N + 1];
  getchar();
  scanf("%[^\n]", S);
  getchar();
  scanf("%[^\n]", T);
  //_S = S + S
  strcpy(_S, S);
  strcat(_S, S);
  //kmp
  int lpps[N + 1];
  kmpPreprocess(T, lpps, N);
  index = kmpSearch(_S, _N, T, lpps, N);
  printf("%d", index <= 0 ? index : N - index);
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

int kmpSearch(char * _S, int n, char * T, int * lpps, int N){
  int i = 0,
      j = 0;
  while (i < n){
    while (j >= 0 && _S[i] != T[j])
      j = lpps[j];
    i++;
    j++;
    if (j == N){
      return i - j;
    }
  }
  return -1;
}
