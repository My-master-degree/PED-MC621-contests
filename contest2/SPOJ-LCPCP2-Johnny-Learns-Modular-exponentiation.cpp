#include <stdio.h>

using namespace std; 

unsigned long pow_mod(unsigned long, unsigned long long, unsigned long);
 
int main() 
{ 
 
	unsigned int t;
	scanf("%u", &t);
	unsigned int i;
	unsigned long m;
	unsigned long b;
	unsigned long outputs[t];
	unsigned long long e;
	for (i = 0; i < t; i++){
		scanf("%lu %llu %lu", &b, &e, &m);
		outputs[i] = pow_mod(b, e, m);
//		printf("%d. %lu\n", i + 1, outputs[i]);	
	}
	for (i = 0; i < t; i++){
		printf("%d. %d\n", i + 1, outputs[i]);
	}
	return 0; 
} 

unsigned long pow_mod(unsigned long b, unsigned long long e, unsigned long m){
	if (!e)
		return 1;
	unsigned long p = pow_mod(b, e/2, m)%m;
	if (e&1)
		return (((p*p)%m)*(b%m))%m;
	return (p*p)%m;	
}

