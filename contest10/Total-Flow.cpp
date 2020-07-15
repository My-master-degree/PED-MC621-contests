#include<bits/stdc++.h>

#define MAX_V 52
#define MAX_VAL 10000000
#define vi vector<int>

using namespace std;

int flows[MAX_V][MAX_V];
int residual[MAX_V][MAX_V];
int dist[MAX_V];
int p[MAX_V];
int N, 
    i, 
    j,
    flow,
    max_flow,
    source,
    target,
    u,
    v;  
char from, 
     to;

int index(char a);
void augment(int v, int minEdge);

int main(){
  //setting up values
  source = index('A');
  target = index('Z');
  for (i = 0; i < MAX_V; i++)
    for (j = 0; j < MAX_V; j++){
      flows[i][j] = 0;
      residual[i][j] = 0;
    }
  //read data
  scanf("%d", &N);
  getchar();
  while(N--){
    scanf("%c %c %d", &from, &to, &flow);
    getchar();
    residual[index(from)][index(to)] = flows[index(from)][index(to)] + flow;
    flows[index(from)][index(to)] = flows[index(from)][index(to)] + flow;      
  }


  for (i = 0; i < MAX_V; i++)
    for (j = 0; j < MAX_V; j++)
      if (residual[i][j] > 0){
        char f = i < 26 ? 'A' + i : 'a' + i;
        char t = j < 26 ? 'A' + j : 'a' + j;
//        printf("%c %c %d\n", f, t, residual[i][j]);
      }

  //edmonds karp
  max_flow = 0;
  while(true){
    flow = 0;
    for (i = 0; i < MAX_V; i++){
      dist[i] = MAX_VAL;
      p[i] = -1;
    }
    p[source] = 0;
    queue<int> q;
    q.push(source);
    while(!q.empty()){
      u = q.front();
      q.pop();
      if (u == target)
        break;
      for (v = 0; v < MAX_V; v++)
        if (residual[u][v] > 0 && dist[v] == MAX_VAL){
          dist[v] = dist[u] + 1;
          q.push(v);
          p[v] = u;
        }
    }
    augment(target, MAX_VAL);
    if (flow == 0)
      break;
    max_flow += flow;
  }
  printf("%d", max_flow);
  return 0;
}

int index(char a){
  return 'A' <= a && a <= 'Z'?  a - 'A' : a - 'a' + 'z' - 'a' + 1;
}

void augment(int v, int minEdge){
  if (v == source)
    flow = minEdge;
  else if (p[v] != -1){
    augment(p[v], min(minEdge,  residual[p[v]][v]));
    residual[p[v]][v] -= flow;
    residual[v][p[v]] += flow;
  }
}
