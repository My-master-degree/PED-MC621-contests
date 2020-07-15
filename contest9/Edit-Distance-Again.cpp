#include<bits/stdc++.h>

#define MAX 1000

using namespace std;

bool isLC(char c){
  return 'a' <= c && c <= 'z';
}

int main(){
  char S[MAX + 1];  
  int i,
      n,
      c1,
      c2;
  while (cin>>S){
    n = strlen(S);
    c1 = c2 = 0;
    for (i = 0; i < n; i++){
      if (i%2 == 0 && !isLC(S[i]))
        c1++;
      else if (i%2 == 1 && isLC(S[i]))
        c1++;
      if (i%2 == 0 && isLC(S[i]))
        c2++;
      else if (i%2 == 1 && !isLC(S[i]))
        c2++;
    }
//    printf("%s %d %d\n", S, c1, c2);
    printf("%d\n", min(c1, c2));
  }
  return 0;
}
