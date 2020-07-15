#include<bits/stdc++.h>

#define MAX_N 20
#define MAX_M 20

using namespace std;

int A[MAX_N][MAX_M],
    ACost[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int N, M;

typedef struct _Cell{
  int x,
      y;
} Cell;

typedef struct _State{
  Cell cell;
  int cost;
} State;

bool isValidCell(Cell cell){
  return cell.x < M && cell.y < N && !visited[cell.x][cell.y] && A[cell.x][cell.y];
}

Cell left(Cell * cell){
  return {cell.x - 1, cell.y};
}


Cell right(Cell * cell){
  return {cell.x + 1, cell.y};
}

Cell down(Cell * cell){
  return {cell.x, cell.y + 1};
}

Cell top(Cell * cell){
  return {cell.x, cell.y - 1};
}

void visit(Cell * cell){
  visited[cell.x][cell.y] = true;
}

int main(){
  int i, 
      j;
  Cell sr, tr;
  //read
  scanf("%u%u", &N, &M);
  for (i = 0; i < N; i++)
    for (j = 0; j < M; j++){
      scanf("%d", &A[i][j]);
      visited[i][j] = false;
      Acost[i][j] = -1;
    }
  scanf("%d%d", &sr.x, &sr.y);
//  scanf("%d%d", &tr.x, &tr.y);
  tr.x = N - 1;
  tr.y = M - 1;
  //lee's
  bool pathFound = false;
//  int MAX_COST;
  MAX_COST = -1;
  queue<State> q;
//  q.push({sr, 0});
  q.push({sr, A[sr.x][sr.y]});
  visit(u.cell);
  Acost[sr.x][sr.y] = A[sr.x][sr.y];
  while (!q.empty()){
    State u = q.front();
    q.pop();
    //base case
    if (u.cell.x == tr.x && u.cell.y == tr.y){
      pathFound = true;
//      if (u.cost < MAX_COST)
      if (u.cost > MAX_COST)
        MAX_COST = u.cost;
    }
    //left
//    Cell d = left(i&u.cell);
//    if (isValidCell(d))
//      q.push({d, u.cost + 1});
    //right
    d = right(&u.cell);
    if (isValidCell(d) && Acost[u.cell.x][u.cell.y] - A[d.x][d.y] > Acost[d.x][d.y])
//      q.push({d, u.cost + 1});
        q.push({d, u.cost - A[d.x][d.y]});
    //down
    d = down(&u.cell);
    if (isValidCell(d))
//      q.push({d, u.cost + 1});
        q.push({d, u.cost - A[d.x][d.y]});
    //top
//    d = top(&u.cell);
//    if (isValidCell(d))
//      q.push({d, u.cost + 1});
  }

  if (!pathFound)
    printf("-1");
  else
    printf("%d", MAX_COST);
  return 0;
}
