#include<bits/stdc++.h>

#define MAX_PRICE 1000000001
#define vii vector<pair<int, int> >

using namespace std;

int dijkstra(vector<vii > & G, int r){
  queue<int> q;
  vii::iterator it;
  int n = G.size(),
      i,
      t = 0;
  int c[n];
  for (i = 1; i < n; i++)
    c[i] = MAX_PRICE;
  c[r] = 0;
  q.push(r);
  while (q.size() > 0){
    r = q.front();
    q.pop();
    for (it = G[r].begin(); it != G[r].end(); it++){
      if (c[r] + it->second < c[it->first]){
        c[it->first] = c[r] + it->second;
        q.push(it->first);
      }
    }
  }
  for (i = 1; i < n; i++)
    t += c[i];
  return t;
}

int main (){
  int p,
      q,
      n,
      i,
      j,
      w;
  vector<vii > G, _G;
  scanf("%d", &n);
  while (n--){
    scanf("%d%d", &p, &q);
    G.clear();
    _G.clear();
    G.resize(p + 1);
    _G.resize(p + 1);
    while (q--){
      scanf("%d%d%d", &i, &j, &w);
      G[i].push_back(make_pair(j, w));
      _G[j].push_back(make_pair(i, w));
    }
    printf("%d\n", dijkstra(G, 1) + dijkstra(_G, 1));
  }

  return 0;
}
