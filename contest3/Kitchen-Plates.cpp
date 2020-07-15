#include<bits/stdc++.h>

using namespace std;

bool dfs(int node, list<int> adj[], bool visited[], bool stackVisited[], int finalTimestamps[], int *time){
	if (stackVisited[node]){
		return false;
	}
	if (!visited[node]){
		stackVisited[node] = true;
		visited[node] = true;
		for (auto _node : adj[node]){
			if (!dfs(_node, adj, visited, stackVisited, finalTimestamps, time))
				return false;
		}
		finalTimestamps[node] = *time;
		*time = *time + 1;
		stackVisited[node] = false;
	}
	return true;
}

bool descending(const pair<int,int> &a, const pair<int,int> &b) { 
       return (a.first > b.first); 
} 

int main(){
	int i;
	char input[4];
	list<int> lessThanAdj[5], biggerThanAdj[5];
	list<int>::iterator it;
	for (i = 0; i < 5; i++){
		scanf("%s", input);
		if (input[1] == '>'){
			biggerThanAdj[input[0] - 'A'].push_back(input[2] - 'A');
			lessThanAdj[input[2] - 'A'].push_back(input[0] - 'A');
		}else if (input[1] == '<'){
			biggerThanAdj[input[2] - 'A'].push_back(input[0] - 'A');
			lessThanAdj[input[0] - 'A'].push_back(input[2] - 'A');
		}
	}
	//get root
	int root = -1;
	for (i = 0; i < 5; i++){
		if (root >= 0 && biggerThanAdj[i].size() == 0){
			printf("impossible");
			return 0;
		}
		if (biggerThanAdj[i].size() == 0)
			root = i;
	}
	if (root >= 0){
		bool visited[5], stackVisited[5];
		memset(visited, false, 5);
		memset(stackVisited, false, 5);
		int finalTimestamps[5];
		int time = 1;
		if (dfs(root, lessThanAdj, visited, stackVisited, finalTimestamps, &time)){
			bool allVerticesVisited = 1;
			for (i = 0; i < 5; i ++)
				allVerticesVisited &= visited[i];
				
			if (allVerticesVisited){
				vector<pair<int, int> > pairs;
				for (i = 0; i < 5; i++)
					pairs.push_back({finalTimestamps[i], i});
				sort(pairs.begin(), pairs.end(), descending);
				for (i = 0; i < 5; i++)
					printf("%c", pairs[i].second + 'A');	
				return 0;
			}
		}
	}

	printf("impossible");
	
	

	return 0;
}
