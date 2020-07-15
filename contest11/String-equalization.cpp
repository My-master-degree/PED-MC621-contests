#include<bits/stdc++.h>

using namespace std;

int main()
{
  int i, 
      j, 
      k,
      n, 
      m, 
      q;
  string s, 
         t;
  bool f;
  cin>>q;
  while(q--) {
    cin >> s >> t;
    f = false;
    n = s.length();
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++)
        if(s[i] == t[j]) {
          f = true;
          break;
        }
      if(f)
        break;
    }
    if(f)
      cout<<"YES";
    else
      cout<<"NO";
    cout<<endl;
  }
  return 0;
}
