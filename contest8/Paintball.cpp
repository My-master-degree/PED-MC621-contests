#include<bits/stdc++.h>

#define MAX 1000

using namespace std;

bitset<MAX * 2 + 1> p1bs,
        p2bs;
set<int> p1,
          p2;
set<int>::iterator it;
list<int>::iterator it1;

bool _bfs(list<int> * adj, int N);

int main(){
  int M,
      N,
      A,
      B,
      i,
      _N,
      u,
      v;
  bool found;
  scanf("%d%d", &N, &M);
  _N = 2 * (N + 1);
  list<int> adj[_N];
  int targets [N + 1],
      shooter [N + 1];
  for (i = 0; i <= N; i++)
    targets[i] = shooter[i] = 0;
  while(M--){
    scanf("%d%d", &A, &B);
    adj[A].push_back(N + B);
    adj[N + B].push_back(A);
    adj[B].push_back(N + A);
    adj[N + A].push_back(B);
  }
  if (_bfs(adj, N * 2)){    
    for (it = p1.begin(); it != p1.end(); it++){
      u = *it > N ? *it - N : *it;
      found = false;
      for (it1 = adj[*it].begin(); it1 != adj[*it].end(); it1++){
        v = *it1 > N ? *it1 - N : *it1;
        if (p2bs[v] && shooter[v] == 0){
          targets[u] = v;
          shooter[v] = u;
          found = true;
          break;
        }
      }
      if (!found){
        printf("Impossible");
        break;
      }
    }
    for (i = 1; i <= N; i++){
      printf("%d\n", targets[i]);
    }


    printf("Possible");
  }else{
    printf("Impossible");
  }

  return 0;
}

bool _bfs(list<int> * adj, int N){
  int colors[N + 1];
  int u,
      i;
  for (i = 0; i <= N; i++)
    colors[i] = 0;
  queue<int> q;
  for (i = 1; i <= N; i++){
    //check if is not visited
    if (colors[i] == 0){
      //define initial color
      colors[i] = 1;
      printf("%d recevies 1\n", i);
      p1.insert(i);
      p1bs[i] = 1;
      q.push(i);      
      while (!q.empty()){
        u = q.front();
        q.pop();
        for (it1 = adj[u].begin(); it1 != adj[u].end(); it1++){
          if (colors[*it1] == 0){
            if (colors[u] == 1){
              colors[*it1] = 2;
              printf("%d recevies 2\n", *it1);
              p2.insert(*it1);
              p2bs[*it1] = 1;
            }else{
              colors[*it1] = 1;
              p1.insert(*it1);
              p1bs[*it1] = 1;
              printf("%d recevies 1\n", *it1);
            }
            q.push(*it1);
          }else if (colors[*it1] == colors[u])
            return false;
        }
      }
    }
  }
  return true;
}
