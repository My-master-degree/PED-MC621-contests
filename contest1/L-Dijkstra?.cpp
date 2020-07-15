#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <queue> 
#include <limits>
#include <stack> 
#include <string>

using namespace std;

void dfs_print(list<int>*, int, int, bool);

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	if (n < 2 || n > 100000 || m < 0 || m > 100000)
		return 0;
	list<pair<int, int> > adj[n];
	int i;
	for (i = 0; i < m; i++){
		int v1, v2, w;
		scanf("%d %d %d", &v1, &v2, &w);
		bool f = true;
		for (list<pair<int, int> >::iterator itr = adj[v1 - 1].begin(); itr != adj[v1 - 1].end(); ++itr){
			if ((*itr).first == v2 - 1){
				if ((*itr).second > w){
					itr = adj[v1 - 1].erase(itr);
				} else
					 f = false;
				break;
					
			} 
		}
		if (f){
			adj[v1 - 1].push_back(make_pair(v2 - 1, w));
		}
	}
//	dijkstra
	queue<int> q;
	list<int> p[n];
	int c[n];
	memset (c, numeric_limits<int>::max(), sizeof(int) * n);
	c[0] = 0;
	q.push(0);
	while (q.size() > 0){
		int v = q.front(), _v, w;
		q.pop();
		for (list<pair<int, int> >::iterator itr = adj[v].begin(); itr != adj[v].end(); ++itr)	{
			_v = (*itr).first;
			w = (*itr).second;			
			if (p[_v].empty()){			
				p[_v].push_back(v);
				c[_v] = c[v] + w;
				q.push(_v);				
			}else if (c[_v] > c[v] + w){
				c[_v] = c[v] + w;
				p[_v].clear();
				p[_v].push_back(v);
			}else if (c[_v] == c[v] + w){
				p[_v].push_back(v);	
			}			
		}
	}
	for (i = 0; i < n; i++){
		printf("%d: ", i);
		for (list<int>::iterator itr = p[i].begin(); itr != p[i].end(); ++itr)

			printf("%d, ", (*itr));
		printf("\n");
	}
// 	print path
	if (!p[n - 1].empty())
		dfs_print(p, n - 1, 0, "\n");
	else
		printf("-1");

}

void dfs_print(list<int>* p, int i, int b, char[] s){
	if (i == b){
//		printf("base case anchieved\n");
		printf("%d%s", b + 1, s);
	}else{
		for (list<int>::iterator itr = p[i].begin(); itr != p[i].end(    ); ++itr){			
			int j = (*itr);
//			printf("going to %d", j);
			string _s;
			sprintf(_s, " %d%s", j + 1, s);
			dfs_print(p, j, b, _s);
		}
	}
}
