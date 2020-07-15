#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, 
      m,
      i,
      j,
      s = 0;
  scanf("%d%d", &n, &m);
  int a[n][m];
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      scanf("%d", &a[i][j]);    
  for (i = n - 1; i >= 0; i--)
    for (j = m - 1; j >= 0; j--){
      if (a[i][j] == 0)
        a[i][j] = min(a[i][j + 1], a[i + 1][j]) - 1;
      if (i > 0 && a[i][j] <= a[i - 1][j] || j > 0 && a[i][j] <= a[i][j - 1]){
        printf("-1");
        return 0;
      }
      s += a[i][j];
    }
  printf("%d", s);
  return 0;
}
