#include <iostream>
#include <string>

using namespace std;

int main() {
  int a[3];
  string str;
  int t,
      n,
      sum,
      flag,
      len,
      j;
  cin>>t;
  while(t--)
  {
    cin>>n;
    sum = 0;
    flag = 0;
    a[0] = a[1] = 0;
    for(int i = 0; i < n; i++)
    {
      cin>>str;
      len = str.size();
      if(len%2)
        flag = 1;
      for(j = 0; j < len; j++)
        a[str[j]-'0']++;
    }
    if(a[0]%2 && a[1]%2 && !flag)
      n--;
    cout<<n<<endl;
  }
  return 0;
}
