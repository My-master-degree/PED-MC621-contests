#include<bits/stdc++.h>

#define MAX 1000000

using namespace std;

int main(){
  int T, i, j, n, m, k;
  char A[MAX + 1],
        B[MAX + 1];
  scanf("%d", &T);
  while (T--){
    scanf("%s", A);
    getchar();
    scanf("%s", B);
    getchar();
    n = strlen(A);
    m = strlen(B);
    vector<int> out;
    for (i = 0; i < n; i++){
      k = i;
      for (j = 0; k < n && j < m && A[k] == B[j]; j++, k++);
      if (j == m)
        out.push_back(i + 1);
    }
    if (out.size() == 0)
      printf("Not Found");
    else{
      printf("%d\n", int(out.size()));
      for(i = 0; i < out.size(); i++)
        printf("%d ", out[i]);
    }
    printf("\n");
    if (T > 0)
      printf("\n");
  }
  return 0;
}
