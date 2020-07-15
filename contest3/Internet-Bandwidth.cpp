#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	if (n >= 2 && n <= 100){
		int i, nEdges, s, t, from, to, capacity;
		bool edgeFound;
		list<pair<int, int> >::iterator it;
		scanf("%d %d %d", &s, &t, &nEdges);
		vector<list<pair<int, int> > > adj[n];
		for (i = 0; i < nEdges; i++){
			scanf("%d %d %d", from, to, capacity);
			edgeFound = false;	
			for (it = adj[from].begin(); it != adj[from].end(); ++it){
				if (it->first == to){
					it->second += capacity;
					edgeFound = true;
					break;
				}
			}
			if (!edgeFound){
				adj[from].push_back({to, capacity});
				adj[to].push_back({from, capacity});
			}
		}
		
	}
	return 0;
}
