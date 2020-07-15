#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <math.h>       /* pow */

using namespace std;


int digits(int n){
	int d;
	for (d = 0; n > 0; d++){
		n = n/10;
	}
	return d;
}

bool isArmstrongNumber(int n){	
	int _n = n;
	int r = 0;
	int d = digits(_n);
	for (; _n > 0; _n = _n/10){
		r += pow(_n%10, d);
	}
	return n == r;
}

int main()
{
	int t, n, i;
	scanf("%d", &t);
	bool r[t];
	for (i = 0; i < t; i++){
		scanf("%d", &n);
		r[i] = isArmstrongNumber(n);
	}
	for (i = 0; i < t; i++){
		if (!r[i])
			printf("Not ");
		printf("Armstrong\n");
	}
}
