#include<bits/stdc++.h>

#define MAX 100000

typedef long long ll;

using namespace std;

void _merge(int p1[], int l1, int r1, int p2[], int l2, int r2, int r[]);
void  merge_sort(int l, int r, int re[]);

int arr[MAX + 1];
ll S;
int main(){
  int T, N, i;
  scanf("%d", &T);
  while (T--){
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
      scanf("%d", &arr[i]);
    S = 0;
    int arr1[N + 1];
    merge_sort(1, N, arr1);
    printf("%lld\n", S);
  }
  return 0;
}

void  merge_sort(int l, int r, int * re){
  if (l < r){
    int m = (l + r)/2;
    int p1[m - l + 1],
        p2[r - m];
    merge_sort(l, m, p1);
    merge_sort(m + 1, r, p2);
    _merge(p1, l, m, p2, m + 1, r, re);
  }else
    re[1] = arr[l];
}

void _merge(int * p1, int l1, int r1, int * p2, int l2, int r2, int * r){
  int i = l1, j = l2, k = 1;
  while (i <= r1 && j <= r2){
    if (p1[i - l1 + 1] < p2[j - l2 + 1]){
      S += (r2 - j + 1) *(ll) p1[i - l1 + 1];
      r[k] = p1[i - l1 + 1];
      i++;
    } else {
      r[k] = p2[j - l2 + 1];
      j++;
    }
    k++;
  }
  for (; i <= r1; r[k++] = p1[i - l1 + 1], i++);
  for (; j <= r2; j++)
      r[k++] = p2[j - l2 + 1];    
}
