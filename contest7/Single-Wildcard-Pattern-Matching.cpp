#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,
      m,
      i,
      j,
      _i,
      _j;
  scanf("%d%d", &n, &m);
  char s[n + 1],
      t[m + 1];
  getchar();
  scanf("%s", s);
  getchar();
  scanf("%s", t);
  if (m >= n - 1){
    for (i = j = 0; i < n && j < m && s[i] != '*'; i = ++j)
      if (s[i] != t[j]){
        printf("NO");
        return 0;
      }

    if (i == n && j < m || j == m && i < n && s[i] != '*'){
      printf("NO");
      return 0;
    }


    for (_i = n - 1, _j = m - 1; _i >= i && _j >= j && s[_i] != '*'; _i--, _j--)
      if (s[_i] != t[_j]){
        printf("NO");
        return 0;
      }
    printf("YES");
  }else
    printf("NO");
  return 0;
}
