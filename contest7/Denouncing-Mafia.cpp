#include<bits/stdc++.h>

#define MAX 100001

using namespace std;

int main(){
  int N,
      K,
      i,
      buff; 
  scanf("%d%d", &N, &K);
  bitset<MAX> A;
  for(i = 2; i <= N; i++){
    scanf("%d", &buff);
    if (k > 0 && !A[i] && !A[buff]){
      k--;
      A[i] = A[buff] = 1;
    }
  }
  
  return 0;
}
