#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
  bool flag[26];
  string s;
  int T,
      len,
      num;
  cin >> T;
  while(T--)
  {
    memset(flag,false,sizeof(flag));
    cin >> s;
    s+='0';
    len = s.size();
    num = 1;
    for(int i=1;i<len;i++)
    {
//      cout<<"At "<<s[i]<<endl;
      if(s[i] == s[i-1])
        num++;
      else
      {
        if(num&1) 
          flag[s[i-1]-'a'] = true;
        num=1;
      }
    }
    for(int i=0;i<26;i++)
      if(flag[i]) 
        cout << char(i+'a');
    cout << endl;
  }
  return 0;
}
