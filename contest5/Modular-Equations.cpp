#include<bits/stdc++.h>

using namespace std;

int main(){
  int a, 
      b,
      d,
      c = 0, 
      i;
  scanf("%d%d", &a, &b);
  d = a - b;
  if (d != 0){
    for (i = 1; i * i < d; i++)
      if (d%i == 0){
        if (i > b)
          c++;
        if ((d/i) > b)
          c++;
      }
    if (i * i == d && i > b)
      c++;
    printf("%d", c);
  }else
    printf("infinity");

}
