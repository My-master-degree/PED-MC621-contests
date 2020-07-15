#include<bits/stdc++.h>

#define MAX 1000

using namespace std;

int main(){
  int n_banks, 
      i, 
      j, 
      v, 
      net,
      original,
      t = 0;
  int debt[MAX], 
      credt[MAX];
  while (true){
    scanf("%d", &n_banks);
    if (!n_banks)
      break;



    for (i = 1; i <= n_banks; i++)
      debt[i] = credt[i] = 0;

    //read input
    for (original = 0, i = 1; i <= n_banks; i++)
      for (j = 1; j <= n_banks; j++){        
        scanf("%d", &v);
        original += v;
        credt[j] += v;
        debt[i] += v;
      }
    


    //process
    for (net = 0, i = 1; i <= n_banks; i++)
      if (debt[i] - credt[i] >= 0)
        net += debt[i] - credt[i];
    printf("%d. %d %d\n", ++t, original, net);
  }
  return 0;
}
