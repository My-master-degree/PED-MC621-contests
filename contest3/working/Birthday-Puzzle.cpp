#include<stdio.h>
#include<set>
#include<iostream>

using namespace std;

unsigned long long getOrOfSubsets(unsigned int*, unsigned int*, int, int);

int main(){
	int n;
	scanf("%d", &n);
	if (n >= 1 && n <= 20){
		unsigned int a[n];
		unsigned int b[n];
		int i;
		for (i = 0; i < n; i++){
			scanf("%u", &a[i]);
			b[i] = 0;
			if (a[i] < 1 || a[i] > 100000)
				i--;
		}
		cout<< getOrOfSubsets(a, b, n, 0);
	}
	return 0;
}

unsigned long long getOrOfSubsets(unsigned int *a, unsigned int *b, int n, int i){
	unsigned long long c = 0;
//	for (int j = 0; j < n; j++)
//		printf("%u ", b[j]);
//	printf("\n");
	if (i == n){
		for (int j = 0; j < n; j++){
			c |= b[j];
		}
	}else{
		b[i] = 0;
		c = getOrOfSubsets(a, b, n, i + 1);
		b[i] = a[i];
		c += getOrOfSubsets(a, b, n, i + 1);

	}
	return c;
	
}
