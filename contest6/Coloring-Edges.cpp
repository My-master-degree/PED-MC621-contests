#include <bits/stdc++.h>

#define MAX_NODES 5001
#define MAX_EDGES 5000
#define NOT_VISITED 0
#define VISITING 1
#define VISITED 2

#define ii pair<int, int>
#define vii vector<pair<int, int> >

using namespace std;

void dfs();

void _dfs(int r);

int nodeVisitStatus[MAX_NODES];
int edgeColor[MAX_EDGES];
vii adj [MAX_NODES];
int n, 
    m,
    u, 
    v;
bool cycle;

int main (){
  int i;
  scanf ("%d%d", &n, &m);
  for (i = 0; i < m; i++){
    scanf("%d%d", &u, &v);
    adj[u].push_back(make_pair(v, i));
  }
  dfs();
  printf("%d\n", cycle ? 2 : 1);
  for (i = 0; i< m; i++)
    printf("%d ", edgeColor[i]);
  return 0;
}

void dfs(){
  int i;
  for (i = 1; i <= n; i++)
    nodeVisitStatus[i] = NOT_VISITED;
  for (i = 1; i <= n; i++)
    if (nodeVisitStatus[i] == NOT_VISITED)
      _dfs(i);
}

void _dfs(int r){
  nodeVisitStatus[r] = VISITING;
  for (vii::iterator it = adj[r].begin(); it != adj[r].end(); it++){
    int node = it->first,
        index = it->second;
    if (nodeVisitStatus[node] == VISITING){
      edgeColor[index] = 2;
      cycle = true;
    } else {
      edgeColor[index] = 1;
      if (nodeVisitStatus[node] == NOT_VISITED)
        _dfs(node);
    }
  }
  nodeVisitStatus[r] = VISITED;
}
