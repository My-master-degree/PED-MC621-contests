#include<bits/stdc++.h>

using namespace std;

int main(){
  //data
  int m,
      n,
      x,
      y,
      i,
      c,
      u;
  set<int> s;
  //read
  scanf("%d%d", &n, &m);
  list<int> adj [n + 1];
  vector<int> r (n);
  list<int>::iterator it;
  vector<int>::iterator it1;
  int inDegree[n + 1];
  for (i = 1; i <= n; i++)
    inDegree[i] = 0;
  while (m--){
    scanf("%d%d", &x, &y); 
    adj[x].push_back(y);
    inDegree[y]++;
  }
  //enqueue zero in-degree nodes
  for (i = 1; i <= n; i++)
    if (inDegree[i] == 0)
      s.insert(i);
  //khan's 
  c = 0;
  while (s.size() > 0) {
    u = *s.begin();    
    s.erase(s.begin());
    r[c++] = u;
    for (it = adj[u].begin(); it != adj[u].end(); it++)
      if (--inDegree[*it] == 0)
        s.insert(*it);
  }
  if (c < n)
    printf("Sandro fails.");
  else
    for (it1 = r.begin(); it1 != r.end(); it1++)
      printf("%d ", *it1);
  return 0;
}
