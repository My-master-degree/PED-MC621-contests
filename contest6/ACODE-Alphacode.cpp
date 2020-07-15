#include<bits/stdc++.h>

#define MAX 5002

typedef long long ll;

using namespace std;

int main(){
  string s;
  ll v[MAX];
  int i, n;
  while (true){
    getline(cin, s);
    if (s == "0")
      break;
    n = s.length();
    v[n] = 1;
    if (s[n - 1] == '0')
      v[n - 1] = 0;
    else
      v[n - 1] = 1;
    for (i = n - 2; i >= 0; i--){
      if (s[i] - '0' == 0)
        v[i] = 0;
      else{

        v[i] = v[i + 1];
        if ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26)
          v[i] += v[i + 2];
      }
    }
    printf("%lld\n", v[0]);
  }
  return 0;
}
