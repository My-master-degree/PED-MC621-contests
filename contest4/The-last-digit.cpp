#include<bits/stdc++.h>

using namespace std;

int _pow(int a, int b, int m){
  if (b == 0)
    return 1;
  int x = _pow(a, b/2, m);
  if (b&1)
    return (((x*x)%m)*(a%m))%m;
  return (x*x)%m;
}

int main(){
  int t;
  scanf("%d", &t);
  if (t <= 30){
    list<int> outputs;
    int a, b;
    while(t--){
      scanf("%d %d", &a, &b);
      if (a >= 0 && a <= 20 && b >= 0 && b <= 2147483000){
        outputs.push_back(_pow(a, b, 10));
      }
    }
    for(list<int>::iterator it = outputs.begin(); it != outputs.end(); ++it)
      printf("%d\n", *it);
  }
  return 0;
}
