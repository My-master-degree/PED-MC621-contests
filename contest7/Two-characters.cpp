#include<stdio.h>

#define ALPHA_LEN 'z' - 'a'+ 1
#define MAX_STR 1001

//using namespace std;


int main(){
  char L[ALPHA_LEN][ALPHA_LEN];
  int C[ALPHA_LEN][ALPHA_LEN];
  int i,
      j,
      k,
      _c,
      MAX,
      len;
  char c;
  scanf("%d", &len);
  char s[len + 1];
  scanf("%s", s);
  if (len == 1){
    printf("0");
    return 0;
  }
  //zeros
  for (i = 0; i < ALPHA_LEN; i++)
    for (j = 0; j < ALPHA_LEN; j++){
      L[i][j] = '*';
      C[i][j] = 0;
    }
  //DP
  for (k = 0; s[k] != '\0'; k++){
    c = s[k];
    _c = c - 'a';
    for (i = 0; i < ALPHA_LEN; i++){
      //column
      if (L[_c][i] == c)
        C[_c][i] = -1;
      if (C[_c][i] >= 0){
        L[_c][i] = c;
        C[_c][i]++;
      }
      //line
      if (L[i][_c] == c)
        C[i][_c] = -1;
      if (C[i][_c] >= 0){
        L[i][_c] = c;
        C[i][_c]++;
      }
    }
  }
  //print test
//  printf("L\n");
//   for (i = 0; i < ALPHA_LEN; i++){
//     for (j = 0; j < ALPHA_LEN; j++)
//      printf("%c ", L[i][j]);
//    printf("\n");
//  }
//  printf("C\n");
//  for (i = 0; i < ALPHA_LEN; i++){
//    for (j = 0; j < ALPHA_LEN; j++)
//      printf("%d ", C[i][j]);
//    printf("\n");
//  }
  MAX = 0;
  for (i = 0; i < ALPHA_LEN; i++)
    for (j = 0; j < ALPHA_LEN; j++)
      if (C[i][j] > MAX)
        MAX = C[i][j];
  printf("%d", MAX);
  return 0; 
}
