// C++ program to find maximum achievable value 
 // with a knapsack of weight W and multiple 
 // instances allowed. 
 #include<bits/stdc++.h> 

#define MAX_PRICE 1000
#define MAX_K 100
using namespace std; 

int main() 
{ 
//  int n = sizeof(val)/sizeof(val[0]); 
  int t;
  scanf("%d", &t);
  if (t > 0){
    list<int> outputs;
    int k, n, i, j; 
    int *p, *s;
    while(t--){
      scanf("%d %d", &n, &k);
      if (n > 0 && n <= MAX_K && k > 0 && k <= MAX_K){
        p = (int*) malloc(k*sizeof(int));
        s = (int*) malloc(k*sizeof(int));
        for (i = 0; i < k; i++){
          scanf("%d", &p[i]);
          s[i] = p[i];
        }
        for (i=1; i < k; i++) 
          for (j=0; j < i; j++){
            if (p[i - j - 1] == -1 || s[j] == -1)
              continue;
            if (s[i] == -1)
              s[i] = s[j] + p[i - j - 1];
            else
              s[i] = min(s[i], s[j] + p[i - j - 1]); 
          }
        if (k == 0)
          outputs.push_back(0);
        else
          outputs.push_back(s[k - 1]); 
      }
    }
    for (list<int>::iterator it = outputs.begin(); it != outputs.end(); ++it)
      printf("%d\n", *it);
  }
  return 0; 
} 

