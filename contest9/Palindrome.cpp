#include<bits/stdc++.h>

#define MIN 2600
#define MAX 50001
using namespace std;

char s[MAX];

int dp[MIN][MIN];

int f(int i, int j){
  if (i > j)
    return 0;  
  if (i == j)
    return 1;
  if (dp[i][j] > 0)
    return dp[i][j];
  if (s[i] == s[j]){
    if (dp[i + 1][j - 1] > 0)      
      return dp[i][j] = 2 + dp[i + 1][j - 1];
    dp[i + 1][j - 1] = f(i + 1, j - 1);
    dp[i][j] = 2 + dp[i + 1][j - 1];
    return dp[i][j];
  }
  if (dp[i + 1][j] == 0)
    dp[i + 1][j] = f(i + 1, j);
  if (dp[i][j - 1] == 0)
    dp[i][j - 1] = f(i, j - 1);
  return dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
}

int main(){
  int c['z' - 'a' + 1];
  int n, i, j, b;
  scanf("%s", s);
  n = strlen(s) <  MIN ? strlen(s) : MIN;
  for (i = 0; i < n; i++)
    for (j = i; j < n; j++)
      dp[i][j] = i == j ? 1 : 0;
  f(0, n - 1);
  //print
  int l;
  i = 0;
  j = n - 1;
  if (dp[0][n - 1] >= 100){
    l = 101;
  }else{
    l = dp[0][n - 1] + 1;
  }
  int li = 0, ri = l - 2;
  char r[l];
  r[l - 1] = '\0';
  while (li <= ri){
    if (s[i] == s[j]){
      r[li++] = r[ri--] = s[i];
      i++;
      j--;
    }else if (dp[i + 1][j] > dp[i][j - 1]){
      i++;
    }else
      j--;
  }
  printf("%s", r);
  return 0;
}
