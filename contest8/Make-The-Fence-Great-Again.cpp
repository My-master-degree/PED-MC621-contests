#include<bits/stdc++.h>

#define MAX_BOARDS 300001
#define MAX_VAL 1000000000000000001

typedef long long ll;

using namespace std;

int a[MAX_BOARDS],
    b[MAX_BOARDS];
ll M[MAX_BOARDS][3];

int main(){
  int q,
     n,
     i,
     j,
     k;
  ll  m;
  scanf("%d", &q);
  while (q--){
    //read
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
      scanf("%d%d", &a[i], &b[i]);
    //dp
    M[n][0] = 0;
    M[n][1] = b[n];
    M[n][2] = 2 * b[n];
    for (i = n - 1; i >= 1; i--)
      for (j = 0; j <= 2; j++){
        m = MAX_VAL;
        for (k = 0; k <= 2; k++)
          if (a[i] + j != a[i + 1] + k && M[i + 1][k] < m)
            m = M[i + 1][k];    
        M[i][j] = m + j * b[i];
      }    
    cout<<min(min(M[1][0], M[1][1]), M[1][2])<<endl;
  }
  return 0;
}
