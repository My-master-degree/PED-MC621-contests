#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool rec(int n1, int n2, int k1, int k2, bool t);

int main()
{
	int n1, n2, k1, k2;
	scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
	if (n1 >= 1 && n2 >= 1 && k1 >= 1 && k2 >= 1 && n1 <= 50 && n2 <= 50 && k1 <= 50 && k2 <= 50){
		if (rec(n1, n2, k1, k2, true))
			printf("First");
		else
			printf("Second");
	}
	return 0;
}

/*
t == true if is player 1 turns
t == false if is player 2 turns

if function returns false, then player two won, otherwise, player one won
*/
bool rec(int n1, int n2, int k1, int k2, bool t){
	if (t){
		if (n1 == 0)
			return false;
		return rec(n1 - 1, n2, k1, k2, !t);
	}
	if (n2 == 0)
		return true;
	return rec(n1, n2 - 1, k1, k2, !t);
}
