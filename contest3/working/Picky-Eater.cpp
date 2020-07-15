#include<bits/stdc++.h>

using namespace std;

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	if (x >= 1 && x <= 10 && y >= 1 && y <= 10){
		if (x >= y)
			printf("1");
		else
			printf("0");
	}
	return 0;
}
