#include<bits/stdc++.h>

#define MAX 10000

using namespace std;

int main(){
  int q,
      m = 10,
      n,
      i,
      j;
  char h[] = "hackerrank\0",
       s[MAX + 1];
  scanf("%d", &q);
  while (q--){
    scanf("%s", s);
    n = strlen(s); 
    i = 0;
    for (j = 0; j < n; j++)
      if (s[j] == h[i])
        i++;
    if (i == m)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
