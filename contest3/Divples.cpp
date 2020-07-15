#include<bits/stdc++.h>

#define ll long long

#define MAX 1000000000000

using namespace std;

int main(){
	ll a, b;
	cin>>a>>b;
	if (a >= 1 && a <= MAX && b >= 1 && b <= MAX){
		int i;
		for (i = b; i <= a/2; i += b)
			if (a%i == 0 && i%b == 0)
				cout<<i<<" ";
		if (a%b == 0)
			cout<<a;
	}
	return 0;
}
