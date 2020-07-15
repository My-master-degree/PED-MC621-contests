#include <stdio.h>
#include <list>
#include <iterator>
#include <algorithm>

typedef long long BIG;

using namespace std;

void update_fib(BIG n);

list<BIG> f;

int main()
{
    short t;
    scanf("%hd", &t);
	if (t >= 1 && t <= 1000){
		list<BIG>::iterator it1;
		BIG n;
		while (t--){
			scanf("%lli", &n);	
			if (n >= 0 && n < 1000000000000){
				update_fib(n);
				it1 = find(f.begin(), f.end(), n);
				int d = distance(f.begin(), it1);
				if (d > 4){
					BIG a = *--it1, b, c;
					--it1;
					b = *--it1;
					c = *--it1;
					printf("%lld %lld %lld\n", c, b, a);
				}else{
					printf("impossible\n");
				}
			}else{
				t++;
			}
		}
	}
    return 0;
}

void update_fib(BIG n){
	if (n > 0 && f.empty()){
		f.push_back(1);
		f.push_back(1);
	}
	for (list<BIG>::iterator c = f.end(); *--f.end() < n; c = f.end()){
		f.push_back(*--c + *++f.rbegin());
	}

		
}


