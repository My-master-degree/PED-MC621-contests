#include<bits/stdc++.h>

#define MAX 1000001

using namespace std;

int lpps[MAX];
int m;

  char S[MAX];
void kmpPreprocess (){
  int i = 0,
      j = -1;
  lpps[0] = -1;
  while (i < m){
    while (j >= 0 && S[i] != S[j])    
      j = lpps[j];
    i++;
    j++;
    lpps[i] = j;
  }
}


int main(){
  scanf("%s", S);
  m = strlen(S);
  kmpPreprocess();
  int i;
  if (lpps[m] == 0){
  
    printf("Just a legend");
    return 0;
  }

  for (i = 1; i < m; i++)
    if (lpps[i] == lpps[m]){
      for(i = 0; i < lpps[m]; i++)
        printf("%c", S[i]);
      return 0;
    }
  if (lpps[lpps[m]] > 0)
    for(i = 0; i < lpps[lpps[m]]; i++)
      printf("%c", S[i]);
  else
    printf("Just a legend");

  return 0;
}
