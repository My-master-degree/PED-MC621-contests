#include<bits/stdc++.h>

using namespace std;

int main(){
  //vars
  int q,
      pos,
      l,
      r,
      n,
      i,
      o,
      a;
  char c;
  char S[100001];
  vector<set<int> > indexes (26);
  set<int>::iterator it;
  //read
  scanf("%s", S);
  scanf("%d", &q);
  //populate indexes
  for (i = 0; S[i] != '\0'; i++)
    indexes[S[i] - 'a'].insert(i + 1);
  while (q--){
    scanf("%d", &o);
    if (o == 1){
      scanf("%d %c", &pos, &c);
      pos--;
      indexes[S[pos] - 'a'].erase(pos + 1);
      S[pos] = c;
      indexes[S[pos] - 'a'].insert(pos + 1);
    } else {
      scanf("%d%d", &l, &r);
      a = 0;
      for (c = 'a'; c <= 'z'; c++){
        it = indexes[c - 'a'].lower_bound(l);
        if (it != indexes[c - 'a'].end() && *it <= r)
          a++;
      }
      printf("%d\n", a);
    }
    
  }
  return 0;
}
