#include<bits/stdc++.h>

using namespace std;

int main(){
  float V, N, p;
  scanf("%f%f", &V, &N);

  printf("%.0f ", ceil(V * N * 0.1));
  printf("%.0f ", ceil(V * N * 0.2));
  printf("%.0f ", ceil(V * N * 0.3));
  printf("%.0f ", ceil(V * N * 0.4));
  printf("%.0f ", ceil(V * N * 0.5));
  printf("%.0f ", ceil(V * N * 0.6));
  printf("%.0f ", ceil(V * N * 0.7));
  printf("%.0f ", ceil(V * N * 0.8));
  printf("%.0f", ceil(V * N * 0.9));
  return 0;
}
