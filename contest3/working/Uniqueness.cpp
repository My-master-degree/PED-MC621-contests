//#include<bits/stdc++.h>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<iterator>
#include<iostream> 
#include<algorithm>

#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define minmax(a, b) pair<int, int> (min(a, b), max(a, b))

using namespace std;

map<int, int>::iterator it;
int val;

bool mapStable(map<int, int>* m);

int main(){
	int n;
	scanf("%d", &n);	
	if (n >= 1 && n <= 2000){
		int a[n];
		int i, j, min = n - 1;
		bool valid_prefix;
		map<int, int> m;
		for (i = 0; i < n; i++){
			scanf("%d", &a[i]);	
		}
		for (i = 0; i < n; i++)	{
			valid_prefix = true;
			for (j = 0; j < i; j++){
				m[a[j]]++;
				if (m[a[j]] > 1){
					valid_prefix = false;
					break;
				}
			}
			for (j = n - 1; j >= i; j--){
				m[a[j]]++;
				if (m[a[j]] > 1)
					break;
			}
			if (valid_prefix && j + 1 - i < min)
				min = j +1 - i;
			m.clear();
		}
		printf("%d", min);
	
	}
}

bool mapStable(map<int, int>* t){ 
	for (it = t->begin(); it != t->end(); ++it){
		if (it->second != 1){
			return false;				
		}
	}
	return true;
}
