#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int GCD (int a, int b){
  return b == 0 ? a : GCD(b, a%b);
}

int main(){
  int i, 
      j,
      n; 
  ll G;
  while (scanf("%d", &n), n > 0){
    G = 0;
    for(i=1; i < n;i++)
      for(j=i+1;j<=n;j++){
        if (i == j)
          G += i;
        else{
          if (j%i == 0)
            G += i;
          else
            G+=GCD(i,j);
        }
      }
    printf("%lld\n", G);
  }

  return 0;
}
