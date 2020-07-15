#include<bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int main(){ 

  int T, N, i, j, M, _i, _j, nBridges;

  char northCityOS[1001][11],
      southCityOS[1001][11];
  char buffer[11];
  int northCityTrade[1001],
      southCityTrade[1001];

  for (i = 0; i < 1001; i++){
    dp[i][0] = 0;
    dp[0][i] = 0;
  }
  scanf("%d", &T);
  while (T--){
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
      //city name
      scanf("%s %s %d", buffer, northCityOS[i], &northCityTrade[i]);
    scanf("%d", &M);
    for (i = 1; i <= M; i++)
      //city name
      scanf("%s %s %d", buffer, southCityOS[i], &southCityTrade[i]);
    //dp
    for (i = 1; i <= N; i++){
      for (j = 1; j <= M; j++){
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if (strcmp(northCityOS[i], southCityOS[j]) == 0)
          dp[i][j] = max(dp[i][j], northCityTrade[i] + southCityTrade[j] + dp[i - 1][j - 1]);
      }
    }
nBridges = 0;
    //get num of bridges
    i = N;
    j = M;
    while (i >= 1 && j >= 1){
      if (dp[i - 1][j] > dp[i][j - 1]){
        _i = i - 1;
        _j = j;
      }else{
        _i = i;
        _j = j - 1;
      }
      if (strcmp(northCityOS[i], southCityOS[j]) == 0 && dp[_i][_j] < northCityTrade[i] + southCityTrade[j] + dp[i - 1][j - 1]){
          _i = i - 1;
          _j = j - 1;
          nBridges++;
      }   
      i = _i;
      j = _j;
    }
    printf("%d %d\n", dp[N][M], nBridges);

  }
  return 0;
}
