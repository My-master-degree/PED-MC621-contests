#include<bits/stdc++.h>

using namespace std;

void swap(int & a, int & b){
  a ^= b;// a = a xor b
  b ^= a;// b = b xor a
  a ^= b;// a = a xor b
}

int main(){
  int n;
  scanf("%d", &n);
  int A[n];
  int i, j, m, k;
  for (i = 0; i < n; i++)
    scanf("%d", &A[i]);
  vector<pair<int, int> > out;
  for (i = 0; i < n; i++){
    k = i;
    for (j = i + 1; j < n; j++)
      if (A[j] < A[k])
        k = j;
    if (k != i){
      out.push_back(make_pair(i, k));
      swap(A[i], A[k]);
    }
  }
  printf("%d\n", int(out.size()));
  for (i = 0; i < out.size(); i++)
    printf("%d %d\n", out[i].first, out[i].second);
  return 0;
}
