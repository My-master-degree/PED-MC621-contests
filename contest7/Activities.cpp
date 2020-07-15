#include <bits/stdc++.h>

#define MAX_CLASSES 100001
#define ii pair<int, int>
#define vii vector<ii >
#define MOD 100000000
#define ll long long

using namespace std;

void dp();
int BS(int val);

int N;
ll D[MAX_CLASSES];
vii A (MAX_CLASSES);  

int main(){
  int i,
      _b,
      _e;
  while (true){
    scanf("%d", &N);
    if (N == -1)
      break;
    for (i = 0; i < N; i++){
      scanf("%d%d", &_b, &_e);
      A[i] = make_pair(_b, _e);
    }
    sort(A.begin(), A.begin() + N);
    dp();


    printf("%08lld\n", D[0]);
  }
  return 0;
}

void dp() {
  D[N] = 0;
  D[N - 1] = 1;
  for (int i = N - 2; i >= 0; i--){
//    printf("BS %d : %d\n", A[i].second, BS(A[i].second));
    D[i] = (((1 + D[BS(A[i].second)])%MOD) + (D[i + 1]%MOD))%MOD;
  }
}

int BS(int val){
  int i = 0,
      j = N - 1,
      m;
  while (i < j){
    m = (i + j)/2;
    if (val <= A[m].first)
      j = m;
    else
      i = m + 1;
  }
  if (val > A[i].first)
    return i + 1;
  return i;
}
