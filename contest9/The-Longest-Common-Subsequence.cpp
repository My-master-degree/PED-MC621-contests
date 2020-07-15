#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,
      m,
      i,
      j;
  scanf("%d", &n);
  int s[n + 1];
  for (i = 1; i <= n; i++)
    scanf("%d", &s[i]);
  scanf("%d", &m);
  int t[m + 1];
  for (j = 1; j <= m; j++)
    scanf("%d", &t[j]);
  int dp[n + 1][m + 1];
  for (j = 0; j <= m; j++)
    dp[0][j] = 0;
  for (i = 1; i <= n; i++){
    dp[i][0] = 0;
    for (j = 1; j <= m; j++)
      dp[i][j] = s[i] == t[j] ? 
                1 + dp[i - 1][j - 1] : 
                max(dp[i - 1][j], dp[i][j - 1]);
  }
  printf("%d", dp[n][m]);
  return 0;
}

//dp[i][j] = 
//            0,                    if i < 0 || j < 0
//            1 + dp[i - 1][j - 1], if s[i] == t[j]
//            max(dp[i - 1][j], dp[i][j - 1]), otherwise
//            
