#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll x0, 
   y_0, 
   d;
void extendedEuclid(ll a, ll b);
ll gcd(ll a, ll b);


int main(){
  ll a, 
     b, 
     c,
     d;
  cin>>a>>b>>c;
  d = gcd(a, b);
  if (c%d == 0){
    extendedEuclid(a, b);
    cout<<x0 * -c/d<<" "<<y_0 * -c/d;
  }else{
    printf("-1");
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


ll gcd (ll a, ll b){
  if (b == 0)
    return a;
  return gcd(b, a%b);
}
