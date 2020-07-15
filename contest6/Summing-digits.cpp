#include<bits/stdc++.h>

using namespace std;

int digitsSum(int n){
  int s = 0;
  while (n > 0){
    s += n%10;
    n /= 10;
  }
  return s;
}


int main(){
  int n, t;
  while (cin>>n, n != 0){
    t = n;
    while (t > 9)
      t = digitsSum(t);
    cout<<t<<endl;
  }
  return 0;
}
