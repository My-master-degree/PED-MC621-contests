#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

class UnionFind {                                             
  private:
    vi p, rank, setSize;                       
    int numSets;

  public:
    UnionFind(int N) {
      setSize.assign(N, 1); 
      numSets = N; 
      rank.assign(N, 0);
      p.assign(N, 0); 
      for (int i = 0; i < N; i++) 
        p[i] = i; 
    }

    int findSet(int i) { 
      return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }

    bool isSameSet(int i, int j) { 
      return findSet(i) == findSet(j); 
    }

    void unionSet(int i, int j) { 
      if (!isSameSet(i, j)) { 
        numSets--; 
        int x = findSet(i), 
            y = findSet(j);
        // rank is used to keep the tree short
        if (rank[x] > rank[y]) { 
          p[y] = x; 
          setSize[x] += setSize[y]; 
        } else { 
          p[x] = y; 
          setSize[y] += setSize[x];
          if (rank[x] == rank[y]) 
            rank[y]++; 
        } 
      } 
    }

    int numDisjointSets() { 
      return numSets; 
    }

    int sizeOfSet(int i) { 
      return setSize[findSet(i)]; 
    }
};

int main(){
  bool f = false, edgeFind;
  int n, k, u, v, w, m, oldCost, newCost, i;
  list<ii>::iterator it, it1;
  while(cin>>n){
    if (f)
      puts("");
    f = true;
    //get edges
    UnionFind uf(n);
    n--;
    vector<pair<int, ii> > edges;
    oldCost = 0;
    while(n--){
      cin>>u>>v>>w;
      oldCost += w;
      edges.push_back(make_pair(w, ii(v, u)));
    }
    //get new edges
    cin>>k;
    while (k--){
      cin>>u>>v>>w;
      edges.push_back(make_pair(w, ii(u, v)));
    }
    //get old edges
    cin>>m;
    while(m--)
      cin>>u>>v>>w;
    //kruskal
    newCost = 0;
    sort(edges.begin(), edges.end());
    for(i = 0; i < edges.size(); i++){
      pair<int, ii> e = edges[i];
      if (!uf.isSameSet(e.second.first, e.second.second)){
        newCost += e.first;
        uf.unionSet(e.second.first, e.second.second);
      }
    }
    //print
    cout<<oldCost<<endl;
    cout<<newCost<<endl;
  }

  return 0;
}
