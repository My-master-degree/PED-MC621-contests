#include<bits/stdc++.h>

using namespace std;

int main()
{
  int i, 
      j, 
      k,
      n,
      m,
      a, 
      b, 
      c, 
      d, 
      q,
      x,
      y;
  scanf("%d", &q);
  while(q--)
  {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
    x = a / c;
    if(a % c != 0)
      x++;
    y = b / d;
    if(b % d != 0)
      y++;
    if(x + y <= k)
    {
      x += (k - x - y);
      printf("%d %d\n", x, y);
    }
    else
      printf("%d\n", -1);
  }

  return 0;
}
