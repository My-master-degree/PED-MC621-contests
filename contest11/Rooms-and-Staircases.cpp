#include<bits/stdc++.h>

using namespace std;

int main()
{
  int i, 
      j, 
      k, 
      n,
      m,
      q,
      ans,
      l,
      r;
  scanf("%d", &q);
  string s;
  while(q--) {
    scanf("%d", &n);
    cin >> s;
    ans = n;
    l = -1;
    r = -1;
    for(i = n - 1; i >= 0; i--)    
      if(s[i] == '1')
      {
        r = i + 1;
        break;
      }    
    for(i = 0; i < n; i++)    
      if(s[i] == '1')
      {
        l = i + 1;
        break;
      }   
     if (l == n || r == n) 
     ans = 2*n;
     else if(l != -1)
    {
      //if starts in the rightmost cell
      k = (n - l + 1) + max(l, n - l + 1);
      ans = max(ans, k);

      // if starts in the leftmost cell
      k = (n - r + 1) + max(r, n - r + 1);
      ans = max(ans, k);

    }
      printf("%d\n", ans);
  }

  return 0;
}
