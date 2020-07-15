#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll pow_mod(ll base, ll exp, ll mod){
  if (exp == 0)
    return 1%mod;
  ll aux = pow_mod(base, exp/2, mod)%mod,
      result = (aux*aux)%mod;
  if ((exp&1) == 1)
    return (result * (base%mod))%mod;
  return result;
}

int main(){
  ll a, b, i; 
  ll s = 0;
  cin>>a>>b;
  cout<<(a&1 == 1 ? 0 : pow_mod(a/2, b, a));
  return 0; 
}
