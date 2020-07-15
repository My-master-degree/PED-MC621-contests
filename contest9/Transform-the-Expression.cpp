#include<bits/stdc++.h>

#define MAX 400

using namespace std;

int main(){
  int t,
      i, 
      j;
  char S[MAX + 1],
        _S[MAX + 1];
  stack<char> sta;
  scanf("%d", &t);
  while (t--){
    scanf("%s", S);
    getchar();
    for (i = j = 0; S[i] != '\0'; i++){
      if ('a' <= S[i] && S[i] <= 'z')
        _S[j++] = S[i];
      else if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/' || S[i] == '^')
        sta.push(S[i]);
      else if (S[i] == ')'){
        _S[j++] = sta.top();
        sta.pop();
      }
    }
    _S[j] = '\0';
    printf("%s\n", _S);
  }
  return 0;
}
