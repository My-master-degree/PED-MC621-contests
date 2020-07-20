#include<bits/stdc++.h>

#define MAX_TESTS 1000
#define MAX_N 1000000000

using namespace std;

int main(){
	int a, b, n, t;
	scanf("%d", &t);
	if (t >= 1 && t <= MAX_TESTS){
		int results[t], i;
		for (i = 0; i < t; i++){
			scanf("%d %d %d", &a, &b, &n);
			if (a >= 0 && a <= MAX_N && b >= 0 && b <= MAX_N && n >= 0 && n <= MAX_N){
				int aXorB = a^b;
				if (n%3 == 0){
					results[i] = a;
				}else if ((n - 1)%3 == 0){
					results[i] = b;
				}else{
					results[i] = aXorB;
				}
			}
		}
		for (i = 0; i < t; i++){
			printf("%d\n", results[i]);
		}
	}
}
