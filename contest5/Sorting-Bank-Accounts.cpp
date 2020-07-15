#include<bits/stdc++.h>

#define MAX 100 

using namespace std;

int main(){
  int t, n;
  map<string, int> m;
  map<string, int>::iterator it;
  string s;
  scanf("%d", &t);
  while(t--){
    m.clear();
    scanf("%d", &n);
    cin.ignore(100,'\n');
    while (n--){
      getline(cin, s);
//      cout<<s<<endl;
      m[s]++;
    }
    for (it = m.begin(); it != m.end(); it++){
      cout<<it->first<<" "<<it->second<<endl;
    }

  }
  return 0;
}
