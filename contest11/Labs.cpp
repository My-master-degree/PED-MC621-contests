#include<bits/stdc++.h>

using namespace std;

int main()
{
  int i, 
      j, 
      k, 
      n, 
      m, 
      t;
  cin>>n;
  int a[n][n];
  k = 1;
  for(i = 0; i < n; i++)  
    if(i % 2)    
      for(j = n - 1; j >= 0; j--)
        a[j][i] = k++;    
    else    
      for(j = 0; j < n; j++)
        a[j][i] = k++;      
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }

  return 0;
}
