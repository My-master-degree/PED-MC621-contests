#include<bits/stdc++.h>

#define MAX 1000000

using namespace std;

int main(){
  char s[MAX];
  int i;
  scanf("%s", s);
  for (i = 0; s[i] != '\0'; i++)
    if (s[i] >= 'A' && s[i] <= 'Z')
      printf("%c", s[i]);
  return 0;
}
