#include<bits/stdc++.h>

using namespace std;

int main (){
  int n, m;
  string S;
  cin>>n;
  while (n--){
    cin>>S;
    m = S.length();
    if (S == "1" || S == "4" || S == "78")
      cout<<"+"<<endl;
    else if (m > 1 && S[m - 2] == '3' && S[m - 1] == '5')
      cout<<"-"<<endl;
    else if (m > 1 && S[0] == '9' && S[m - 1] == '4')
      cout<<"*"<<endl;
    else if (m > 2 && S[0] == '1' && S[1] == '9' && S[2] == '0')
      cout<<"?"<<endl;
    else
      cout<<"+"<<endl;
  }
  return 0;
}
