#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

#define int LL

void read(int &x) {
  char c;bool flag = 0;
  while((c=getchar())<'0'||c>'9') flag |= (c=='-');
  x=c-'0';while((c=getchar())>='0'&&c<='9') x = (x<<3)+(x<<1)+c-'0';
  flag?x=-x:x;
}

#define N 100020
int n,m,k;
vector<int> u[N],d[N],l[N],r[N];
int uu[N],dd[N],ll[N],rr[N]; 
int main() {
  read(n); read(m); read(k);
  for (int i = 1; i <= n; i++) {
    l[i] = 0; r[i] = m+1;
    l[i].push_back(0);
    r[i].push_back(m+1);
  }
  for (int i = 1; i <= m; i++) {
    //u[i] = 0; d[i] = n+1;
    u[i].push_back(0);
    d[i].push_back(n+1);
  }
  for (int i = 1; i <= k; i++) {
    int x,y; read(x); read(y);
    l[x].push_back(y);
    r[x].push_back(y);
    u[y].push_back(x);
    d[y].push_back(x);
  } 
  for (int i = 1; i <= n; i++) {
    sort(r[i].begin(),r[i].end());
    sort(l[i].begin(),l[i].end(),greater<int>());
  }
  for (int i = 1; i<= m; i++) {
    sort(d[i].begin(),d[i].end());
    sort(u[i].begin(),u[i].end(),greater<int>());
  }
  int L = 0,R = m+1,U = 0,D = n+1;
  int dir = 1,dx = 1,dy = 1;
  LL sum = 1;
  bool turned = 0;
  while(1) {
    int tpx = dx,tpy = dy;
    if (dir == 1) {
      while (r[dx][rr[dx]] < dy) rr[dx]++; 
      dy = min(r[dx][rr[dx]]-1,R-1);
      U = dx;
    }
    if (dir == 2) {
      while(d[dy][dd[dy]] < dx) dd[dy]++;
      dx = min(d[dy][dd[dy]]-1,D-1);
      R = dy; 
    }
    if (dir == 3) {
      while(l[dx][ll[dx]] > dy) ll[dx]++;
      dy = max(l[dx][ll[dx]]+1,L+1);
      D = dx;
    }
    if (dir == 4) {
      while(u[dy][uu[dy]] > dx) uu[dy]++;
      dx = max(u[dy][uu[dy]]+1,U+1);
      L = dy;
    }
    dir++;
    if (dir == 5) dir = 1;
    if (dx==tpx && dy==tpy) {
      if (dx==1 && dy==1 && !turned) {
        turned = 1;
        continue;
      } 
      break;
    }
    sum += abs(dx-tpx)+abs(dy-tpy); 
    //cout<<dx<<" "<<dy<<" "<<sum<<"\n";
  } 
  //cout<<sum<<" ";
  puts(sum+k==1LL*n*m?"Yes":"No");
  return 0;
}
