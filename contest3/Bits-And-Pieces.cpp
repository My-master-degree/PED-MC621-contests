#include<stdio.h>

#define MAX_N 1000000
#define MIN_N 3
#define MAX_VAL 2000000
#define MIN_VAL 0
#define ITERATE(n) for (int i = 0; i< n; i++)
#define ITERATE_FROM(w, n) for (int j = w; j< n; j++)

int main(){
	int n;
	scanf("%d", &n);
	if (n >= MIN_N && n <= MAX_N){
		int max = 0, aux;
		int a[n];
		ITERATE(n){
			scanf("%d", &a[i]);
		}
		ITERATE(n){
			ITERATE_FROM(i + 1, n){
				for (int k = j + 1; k < n; k++){
					aux = a[i]|(a[j]&a[k]);
					if (aux > max)
						max = aux;
				}
			}
		}
		printf("%d", max);
	}
}
