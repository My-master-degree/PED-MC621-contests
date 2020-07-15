#include<bits/stdc++.h>

#define MAX 100001

using namespace std;

int M[26][MAX + 1];
  char S[MAX + 1];
int main(){
  //vars
  int q,
      pos,
      l,
      r,
      n,
      i,
      o,
      a;
  char c;
  //read
  scanf("%s", S);
  scanf("%d", &q);
  //clear matrix
  n = strlen(S);
  for (c = 'a'; c <= 'z'; c++){
    for (i = 0; i <= n; i++)
      M[c - 'a'][i] = 0;    
  }
  //fill matrix
  for (i = 1; i <= n; i++)
    M[S[i - 1] - 'a'][i] = 1;
  for (c = 'a'; c <= 'z'; c++)
    for (i = 1; i <= n - 1; i++)
      M[c - 'a'][i + 1] += M[c - 'a'][i];    
  while (q--){
    scanf("%d", &o);
    if (o == 1){

//      printf("BEFORE:\n");
//      printf("%s\n", S);
//      printf("   ");
//      for (i = 1; i <= n; i++)
//        printf("%d ", i);
//      printf("\n");
//      for (c = 'a'; c <= 'z'; c++){
//        printf("%c: ", c);
//        for (i = 1; i <= n; i++)
//          printf("%d ", M[c - 'a'][i]);
//        printf("\n");
//      }




      scanf("%d %c", &pos, &c);
      for (i = pos; i <= n; i++){
        M[S[pos - 1] - 'a'][i]--;
        M[c - 'a'][i]++;
      }
      S[pos - 1] = c;




//      printf("AFTER:\n");
//      printf("%s\n", S);
//      printf("   ");
//      for (i = 1; i <= n; i++)
//        printf("%d ", i);
//      printf("\n");
//      for (c = 'a'; c <= 'z'; c++){
//        printf("%c: ", c);
//        for (i = 1; i <= n; i++)
//          printf("%d ", M[c - 'a'][i]);
//        printf("\n");
//      }


    } else {




      scanf("%d%d", &l, &r);
      a = 0;
      for (c = 'a'; c <= 'z'; c++)
        if (M[c - 'a'][l] > M[c - 'a'][l - 1] || M[c - 'a'][r] - M[c - 'a'][l] > 0)
          a++;      
      printf("%d\n", a);
    }
    
  }
  return 0;
}
