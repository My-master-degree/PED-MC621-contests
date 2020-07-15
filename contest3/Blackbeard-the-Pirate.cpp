#include<bits/stdc++.h>

#define MAX 1000000

using namespace std;

void adaptadedBFS(pair<int, int> root, char **grid, int h, int w, int **distances){
	bool visited[h][w];
	int x, y;
	pair<int, int> *currentNode;
	memset(distances, MAX, h * w * sizeof(int));
	memset(visited, false, h * w * sizeof(int));
	queue<pair<int, int> > q;
	q.push(root);
	x = root.first;
	y = root.second;
	distances[x][y] = 0;
	while (!q.empty()){
		currentNode = &q.front();
		q.pop();
		x = currentNode->first;
		y = currentNode->second;
		visited[x][y] = true;
		//left
		if (x - 1 > 0 && grid[x - 1][y] == '.' || grid[x - 1][y] == '!' && distances[x - 1][y] > distances[x][y] + 1){
			distances[x - 1][y] = distances[x][y] + 1;
			if (!visited[x - 1][y])
				q.push({x - 1, y});
		}
		//down
		if (x + 1 < h && grid[x + 1][y] == '.' || grid[x + 1][y] == '!' && distances[x + 1][y] > distances[x][y] + 1){
			distances[x + 1][y] = distances[x][y] + 1;
			if (!visited[x + 1][y])
				q.push({x + 1, y});
		}
		//left
		if (y - 1 > 0 && grid[x][y - 1] == '.' || grid[x][y - 1] == '!' && distances[x][y - 1] > distances[x][y] + 1){
			distances[x][y - 1] = distances[x][y] + 1;
			if (!visited[x][y - 1])
				q.push({x, y - 1});
		}
		//right
		if (y + 1 < w && grid[x][y + 1] == '.' || grid[x][y + 1] == '!' && distances[x][y + 1] > distances[x][y] + 1){
			distances[x][y + 1] = distances[x][y] + 1;
			if (!visited[x][y + 1])
				q.push({x, y + 1});
		}
	}
}

int main(){
	int h, w, i, j, n;
	char buff;
	char **grid;
	list<pair<int, int> > treasures;
	list<int> *adj;
	while(true){
		treasures.clear();
		scanf("%d %d", &h, &w);
		if (h <= 0 && w	<= 0)	
			break;
		
		printf("To allocate memory\n");
		grid = (char **) malloc(h * sizeof(char*));
		for (i = 0; i < h; i++){
			grid[i] = (char*) malloc((w * sizeof(char)) + 1);
			scanf("%s", grid[i]);
			for (j = 0; j < w; j++)
				if (grid[i][j] == '!' || grid[i][j] == '@')
					treasures.push_back({i, j});
		}	
		printf("Printing\n");
		for (i = 0; i < h; i++){
			printf("%s\n", grid[i]);
		}
		
		printf("Preprocessing\n");
		for (i = 0; i < h; i++){
			for (j = 0; j < w; j++){
				if (grid[i][j] == '*'){
					grid[i][j] = '~';
					//left
					if (j - 1 > 0)
						grid[i][j - 1] = '~';
					//top
					if (i - 1 > 0)
						grid[i - 1][j] = '~';
					//right
					if (j + 1 < w && grid[i][j + 1] != '*')
						grid[i][j + 1] = '~';
					//down
					if (i + 1 < h && grid[i + 1][j + 1] != '*')
						grid[i + 1][j] = '~';
					//left top diagonal
					if (i - 1 > 0 && j - 1 > 0)
						grid[i - 1][j - 1] = '~';
					//left down diagonal
					if (i + 1 < h && j - 1 > 0 && grid[i + 1][j - 1] != '*')
						grid[i + 1][j - 1] = '~';
					//right down diagonal
					if (i + 1 < h && j + 1 < w && grid[i + 1][j + 1] != '*')
						grid[i + 1][j + 1] = '~';	
					//right top diagonal
					if (i - 1 > 0 && j + 1 < w && grid[i - 1][j + 1] == '*')
						grid[i - 1][j + 1] = '~';
				}
			}
		}		
		for (i = 0; i < h; i++){
			printf("%s\n", grid[i]);
		}
		//create graph
		n = 0;
		for (i = 0; i < h; i++){
			for (j = 0; j < w; j++){
						
			}
		}

		adj = (list<int>*) malloc();
		//get distances
		
		//free memory
		for (i = 0; i < h; i++){  
			free(grid[i]);  
		}     
		free(grid);
		//clear buffer
		while (getchar() != '\n');	
	}
	
	return 0;
}
