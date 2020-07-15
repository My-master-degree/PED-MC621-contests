#include<bits/stdc++.h>

#define MAX 100

using namespace std;

list<int> adj [MAX + 1];
int in_degree [MAX + 1];
vector<int> top_order ;

int main(){
  int N, M, task, k, dependency, i, u;
  priority_queue<int, vector<int>, greater<int> > s;
  list<int>::iterator it;
  for(i = 1; i <= MAX; i++)
    in_degree[i] = 0;
  scanf("%d%d", &N, &M);
  while(M--){
    scanf("%d %d", &task, &k);
    while(k--){
      scanf("%d", &dependency);     
      //task depends of dependency 
      adj[dependency].push_back(task);
      in_degree[task]++;
    }
  }
  //kahns
  for (i = 1; i <= N; i++)
    if (in_degree[i] == 0)
      s.push(i);  
  while(!s.empty()){
    u = s.top();
    s.pop();
    top_order.push_back(u);
    for (it = adj[u].begin(); it != adj[u].end(); it++)
      if (--in_degree[*it] == 0)
        s.push(*it);
  }
  for (i = 0; i < N; i++)
    printf("%d ", top_order[i]);

  return 0;
}
