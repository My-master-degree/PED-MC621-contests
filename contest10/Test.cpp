#include<bits/stdc++.h>

#define N_STR 3
#define MAX 100000

using namespace std;

char s[N_STR][MAX + 1];
int lppss[N_STR][MAX + 1];
int lengths[N_STR];
int distances[N_STR][N_STR];

void kmpPreprocess (char * T, int * lpps, int N);
int kmpDistance(char * T, int N, char * P, int M, int * lpps);
void calculateDistances();
void kmpPreprocessALL();

int main(){
  int i, j, k, d;
  while(cin>>s[0]){
    getchar();
    lengths[0] = strlen(s[0]);
    for (i = 1; i < N_STR; i++){
      scanf("%s", s[i]);
      getchar();
      lengths[i] = strlen(s[i]);
    }
    kmpPreprocessALL();
    calculateDistances();
    d = 1000000000;

    for (i = 0; i < N_STR; i++)
      for (j = 0; j < N_STR; j++)
        if (i != j){
         // printf("%s %s %d\n", s[i], s[j], distances[i][j]);
        }
//      printf("----");

    for (i = 0; i < N_STR; i++)
      for (j = 0; j < N_STR; j++)
        if (i != j)
          for(k = 0; k < N_STR; k++)
            if (i != k && j != k){             
              if (distances[i][k] == lengths[i]) 
                d = min(d, distances[i][j]);
              else if (distances[k][i] == lengths[k])
                d = min(d, distances[k][j]);
              else{
                int overlap = lengths[j] + lengths[k] - distances[j][k];
//                printf("%s %s %s %d\n", s[i], s[j], s[k], distances[i][j] + lengths[k] - overlap);
                d = min(d, distances[i][j] + lengths[k] - overlap);
              }
            }
    printf("%d\n", d);
  }
  return 0;
}



void calculateDistances(){
  for (int i = 0; i < N_STR; i++)
    for (int j = 0; j < N_STR; j++)
      if (i != j)
          distances[i][j] = kmpDistance(s[i], lengths[i], s[j], lengths[j], lppss[j]);
}

int kmpDistance(char * T, int N, char * P, int M, int * lpps){
  int i = 0,
      j = 0;
  while (i < N){
    while (j >= 0 && T[i] != P[j])
      j = lpps[j];
    i++;
    j++;
    if (j == M)
      return N;        
  }
  if (T[i - 1] == P[j - 1])
    return N + M - j;
  else
    return N + M;
}

void kmpPreprocessALL(){
  for (int i = 0; i < N_STR; i++)
    kmpPreprocess(s[i], lppss[i], lengths[i]);  
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

