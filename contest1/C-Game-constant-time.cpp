#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main()
{
	int n1, n2, k1, k2;
	scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
	if (n1 >= 1 && n2 >= 1 && k1 >= 1 && k2 >= 1 && n1 <= 50 && n2 <= 50 && k1 <= 50 && k2 <= 50){
		if (n1 <= n2)
			printf("Second");
		else
			printf("First");
	}
	return 0;
}
