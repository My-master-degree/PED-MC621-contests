#include<bits/stdc++.h>

#define MAX 200001

typedef long long ll;

using namespace std;

ll N_INV;

void merge(int * B, int n, int * C, int m, int * D);
int * merge_sort(int * A, int n);
int * _merge_sort(int * A, int i, int j);

int main(){
  int t, n, i;
  int A[MAX];
  scanf("%d", &t);
  while (t--){
    scanf("%d", &n);
    for(i = 0; i < n; i++)
      scanf("%d", &A[i]);
    N_INV = 0;
    merge_sort(A, n);
    printf("%lld\n", N_INV);
  }
}

int * merge_sort(int * A, int n){
  return _merge_sort(A, 0, n - 1);  
}

int * _merge_sort(int * A, int i, int j){
  int * B, * C, * D, m;
  if (i == j){
    D = (int *) malloc(sizeof(int));
    D[0] = A[i];
  }else{
    D = (int *) malloc((j - i) * sizeof(int));
    m = (i + j)/2;
    B = _merge_sort(A, i, m);
    C = _merge_sort(A, m + 1, j);
//    printf("i j m\n");
//    printf("%d %d %d\n", i, j, m);
    merge(B, m - i + 1, C, j - m, D);
  }
  return D;
}

void merge(int * B, int n, int * C, int m, int * D){
  int i, j, k;
  for (k = i = j = 0; i < n && j < m;) 
    if (B[i] <= C[j])
      D[k++] = B[i++];        
    else {
      D[k++] = C[j++];
      N_INV += n - i;
    }  
  for(; i < n; ){
    D[k++] = B[i++];
  }

  for(; j < m; ){
    D[k++] = C[j++];
  }
//  printf("D:\n");
//  for (k = 0; k < n + m ; k++)
//    printf("%d ", D[k]);
//      printf("\n");
}
