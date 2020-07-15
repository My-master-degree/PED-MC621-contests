#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll x0, 
   y_0, 
   d;
void extendedEuclid(ll a, ll b);
ll gcd(ll a, ll b);


int main(){
  ll n, 
     a,
     b, 
     s;
  int t;
  char op;
  while(scanf("%lld%d", &n, &t), n && t){
    while (t--){
      scanf("%lld", &a);
      getchar();
      scanf("%c", &op);
      
      scanf("%lld", &b);
      if (op == '+')
        s = ((a%n) + (b%n))%n;
      else if (op == '-')
        s = ((a%n) + n - (b%n))%n;
      else if (op == '*')
        s = ((a%n) * (b%n))%n;
      else {
        d = gcd(b, n);
        if (d != 1){
          s = -1;
        } else {
          extendedEuclid(b, n);
          s = ((a%n)*((x0 + n)%n))%n;
        } 
      }
      printf("%lld\n", s);
    }
  }

  return 0;
}

void extendedEuclid (ll a, ll b){
  if (b == 0){
    x0 = 1;
    y_0 = 0;
    d = a;
  } else {
    extendedEuclid(b, a%b);
    ll x1 = y_0,
       y1 = x0 - (a/b) * y_0;
    x0 = x1;
    y_0 = y1;
  }
}

ll gcd(ll a, ll b){
  if (b == 0)
    return a;
  return gcd(b, a%b);
}
