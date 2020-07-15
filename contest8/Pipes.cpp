#include<bits/stdc++.h>

#define MAX 200000

using namespace std;

bool isKnee(char a);

int main (){
  int q, 
      n,
      i,
      f1,
      f2,
      _f1,
      _f2;
  bool ok;
  char M[3][MAX + 1];
  scanf("%d", &q);
  while (q--){
    scanf("%d", &n);

    scanf("%s", M[1]);
    scanf("%s", M[2]);


//    printf("%s\n", M[1]);
//    printf("%s\n", M[2]);

    f1 = isKnee(M[1][0]) ? 2 : 1;
    f2 = f1 == 2 && isKnee(M[2][0]) ? 2 : 0;
    ok = true;
    for (i = 1; i < n; i++){
//      printf("Iteration %d\n", i);
//      printf("\tf1: %d\n", f1);
//      printf("\tf2: %d\n", f2);
      //row 1
      if (f1 == 1)
        _f1 = isKnee(M[1][i]) ? 2 : 1;
      else
        _f1 = 0;
      //row 2
      if (f2 == 2)
        _f2 = isKnee(M[2][i]) ? 1 : 2;
      else if (_f1 == 2)
        _f2 = isKnee(M[2][i]) ? 2 : 0;
      else
        _f2 = 0;
      //row 1 again
      if (_f2 == 1)
        _f1 = isKnee(M[1][i]) ? 1 : 0;
      //check
      if (_f1 == 0 && _f2 == 0){
        ok = false;
        break;
      }
      f1 = _f1;
      f2 = _f2;
    }
    if (ok && f2 == 2)
      printf("YES\n");
    else
      printf("NO\n");
  }
}

bool isKnee(char a){
  return '3' <= a && a <= '6';
}
