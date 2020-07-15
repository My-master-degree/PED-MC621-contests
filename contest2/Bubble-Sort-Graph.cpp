#include <stdio.h>
#include <iostream> 
#include <algorithm>
#include <map>
#include <iterator> 
#include <set> 

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	if (n >= 2 && n <= 100000){
		int i, j, b, p;
		int arr[n], B[n], P[n];
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		for (i = 0; i< n; i++){
			b = 0;
			j = 0;
			for (j = 0; j < i; j++)	
				if (arr[j] <= arr[i] && B[j] > b){
					b = B[j];
					p = j;
				}
			if (b == 0){
				B[i] = 1;
				P[i] = i;
			}else{
				P[i] = p;
				B[i] = b + 1;
			}
		}
		//get bigger
		b = 0;
		for (i = 0; i < n; i++)
			if (B[i] > b){
				b = B[i];
				j = i;
			}			
		for (i = 1; P[j] != j; i++, j = P[j]);
		printf("%d", i);
		
	}
	//
	return 0;
}

