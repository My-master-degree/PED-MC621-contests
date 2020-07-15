#include<bits/stdc++.h>

using namespace std;

int main(){
  int q,
      m,
      c,
      x,
      d,
      r;
  scanf("%d", &q);
  while(q--){
    scanf("%d%d%d", &c, &m, &x);
    d = abs(c - m);
    if (c >= m)
      c -= d;
    else
      m -= d;
    x += d;
    if (x > m)
      r = m;
    else{
      r = x;
      m -= x;
      c -= x;
      r += (m + c)/3;
    }
    printf("%d\n", r);

  }
  return 0;
}
