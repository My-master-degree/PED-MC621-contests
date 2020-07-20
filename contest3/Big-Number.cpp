#include<bits/stdc++.h>

using namespace std;

int main(){
	int t, n, i;
	double aux;
	list<int> l;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		if (n >= 1 && n <= 10000000){
			aux = 0;	
			for (i = 1; i <= n; i++){
				aux += log10(i);
			}
			l.push_back(((int)aux) + 1);
		}
		
	}
	for (list<int>::iterator it = l.begin(); it != l.end(); it++){
		printf("%d\n", *it);
	}
	return 0;
}
