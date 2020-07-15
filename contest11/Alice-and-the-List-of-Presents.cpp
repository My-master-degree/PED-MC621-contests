#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

ll mod = 1e9 + 7;
ll fast_expo(ll x, ll y) {
  ll res = 1;
  x = x % mod;
  while (y > 0)
  {
    if (y & 1)
      res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return (res + mod) % mod;
}

int main()
{
  int i, 
      j, 
      k;
  ll n, m;
  cin>>n>>m;
  ll temp = fast_expo(2, m) - 1;
  cout << (fast_expo(temp, n)) % mod << endl;
  return 0;
}
