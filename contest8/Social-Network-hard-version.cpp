#include<bits/stdc++.h>

#define MAX 1000000001

using namespace std;

bitset<MAX> bs;

void print_reversed_queue(queue<int> * q);

int main(){
  int n,
      k,
      aux;
  queue<int> messages;
  scanf ("%d%d", &n, &k);
  while (n--){
    scanf("%d", &aux);
    if (!bs[aux]){
      if (messages.size() == k){
        bs[messages.front()] = 0;
        messages.pop();
      }
      bs[aux] = 1;
      messages.push(aux);
    }
  }
  printf("%d\n", int(messages.size()));
  print_reversed_queue(&messages);
  return 0;
}

void print_reversed_queue(queue<int> * q){
  if (q->size() > 0){
    int f = q->front();
    q->pop();
    print_reversed_queue(q);
    printf("%d ", f);
  }
}
