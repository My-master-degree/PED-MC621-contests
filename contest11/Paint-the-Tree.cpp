#include<bits/stdc++.h>

typedef long long int ll;

#define N 100001
using namespace std;

vector<int> adj[N];
vector<int> color[N];

ll sum;
int a[] = {0, 1, 2};
int ans[N];

void dfs(int s, int p, int c) {
  sum += color[s][a[c]];
  ans[s] = a[c] + 1;
  for(int e : adj[s])
    if(e != p)
      dfs(e, s, (c + 1) % 3);
}

int main() {
  int i, 
      j, 
      k, 
      n, 
      m, 
      u, 
      v,
      src;
  cin>>n;
  for(i = 0; i < 3; i++)
    for(j = 1; j <= n; j++){
      cin>>m; 
      color[j].push_back(m);  
    }
  for(i = 1; i < n; i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(i = 1; i <= n; i++)
  {
    if(adj[i].size() == 1)
      src = i;
    if(adj[i].size() > 2)
    {
      cout<<-1;
      return 0;
    }
  }
  ll mn = 1e18;
  vector<int> ans2;
  do{
    sum = 0;
    dfs(src, -1, 0);
    if(mn > sum) {
      mn = sum;
      ans2.clear();
      for(j = 0; j < 3; j++)
        ans2.push_back(a[j]);
    }
  }while(next_permutation(a, a + 3));
  cout<<mn<<endl;
  a[0] = ans2[0];
  a[1] = ans2[1];
  a[2] = ans2[2];
  dfs(src, -1, 0);
  for(i = 1; i <= n; i++)
    cout<<ans[i]<<" ";
  return 0;
}
