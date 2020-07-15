#include<bits/stdc++.h>

using namespace std;

int f (int x){
  int s = 0;
  while (x != 0){
    s += (x%10)*(x%10);
    x = x/10;
  }
  return s;
}

int happyNumber(int x0){
  if (x0 == 1)
    return 1;
  int tortoise = x0, 
      hare = f(x0), 
      hareIndex = 2, 
      tortoiseIndex = 1;
  while (tortoise != hare){
    if (tortoise == 1){
      return tortoiseIndex;
    }
    if (hare == 1){
      while (tortoise != 1){
        tortoise = f(tortoise);
        tortoiseIndex++;
      }
      return tortoiseIndex;
    }
    tortoiseIndex++;
    hareIndex += 2;
    tortoise = f(tortoise);
    hare = f(f(hare));
  }
  return -1;
}

int main (){
  int l, 
      h, 
      i, 
      r, 
      flag = 0;
  while(scanf("%d %d", &l, &h) == 2) {
    if(flag)
      puts("");
    flag = 1;
    for (i = l; i <= h; i++) {
      r = happyNumber(i);
      if (r > 0)
        printf("%d %d\n", i, r);
    }
  }
  return 0;
}
