#include<bits/stdc++.h>

using namespace std;

int main(){
  int n ,k, n_dependent_courses, depends, main_course;
  scanf("%d%d", &n, &k);
  int main_courses[k + 1];  
  list<int> adj[n + 1];
  for (int i = 1; i <= k; i++){
    scanf("%d", &main_course);
    main_courses[i] = main_course;
  }
  for (int i = 1; i <= n; i++){
    scanf("%d", &n_dependent_courses);
    while (n_dependent_courses-){
      scanf("%d", &depends);
      adj[i].push_back(depends);
    }
  }
  //bfs
  <int> nodes;
  for (int i = 1; i <= k; i++) {
  }
  return 0;
}

