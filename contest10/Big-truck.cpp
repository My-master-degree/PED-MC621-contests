#include<bits/stdc++.h>

#define MAX_V 100
#define MAX_D 101

using namespace std;

int n_itens[MAX_V + 1];
int distances[MAX_V + 1][MAX_V + 1];
int prede[MAX_V + 1];
int cost[MAX_V + 1];
int itens[MAX_V + 1];

int main(){
  int n, i, m, a, b, j, u, count, v;
  queue<int> q;
  scanf("%d", &n);
  for (i = 1; i <= n; i++){
    scanf("%d", &n_itens[i]);
    prede[i] = 0;
    cost[i] = MAX_D;
    for (j = 1; j <= n; j++)
      distances[i][j] = 0;
  }
  scanf("%d", &m);
  for (i = 1; i <= m; i++){
    scanf("%d%d", &a, &b);
    scanf("%d", &distances[a][b]);
    distances[b][a] = distances[a][b];
  }
  //dijkstra
  q.push(1);
  cost[1] = 0;
  prede[1] = 1;
  itens[1] = n_itens[1];
  while (!q.empty()){
    u = q.front();
    q.pop();
    for (v = 1; v <= n; v++)      
      if (distances[u][v] > 0)
        if (cost[v] > cost[u] + distances[u][v] || cost[v] == cost[u] + distances[u][v] && itens[v] < itens[u] + n_itens[v]){
          prede[v] = u;
          cost[v] = cost[u] + distances[u][v];
          itens[v] = itens[u] + n_itens[v];
          q.push(v);
        } 
  }
  //count itens from path
  if (prede[n] != 0){
    for (u = n, count = n_itens[u]; u != 1; count += n_itens[u = prede[u]]);
    printf("%d %d", cost[n], count);
  }else
    printf("impossible");

  return 0;
}
