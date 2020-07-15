#include<bits/stdc++.h>

using namespace std;

int main()
{
  int i, 
      j, 
      k,
      n,
      m, 
      t;
  string s;
  cin>>t;
  while(t--) {
    cin >> s;
    vector<int> odd, even;
    n = s.length();
    for(i = 0; i < n; i++) {
      k = s[i] - '0';
      if(k % 2)
        odd.push_back(k);
      else
        even.push_back(k);
    }
    i = 0, j = 0;
    while(i < even.size() || j < odd.size())
    {
      if(i < even.size() && j < odd.size())
        if(even[i] <= odd[j])
          cout<<even[i++];
        else
          cout<<odd[j++];
      else if(i < even.size())
        cout<<even[i++];
      else
        cout<<odd[j++];
    }
    cout<<endl;
  }

  return 0;
}
