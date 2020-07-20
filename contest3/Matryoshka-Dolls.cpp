#include<stdio.h>

#define MAX 1000000000

using namespace std;

int main(){
	int s, x;
	scanf("%d %d", &s, &x);
	if (s >= 1 && s <= MAX && x >= 2 && x <= MAX){
		int c = 0;
		while (s >= 1){
			s = s/x;
			c++;
		}
		printf("%d", c);
	}
	return 0;
}
