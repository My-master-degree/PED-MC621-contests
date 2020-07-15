#include <stdio.h>
#include <limits>

using namespace std;

int main()
{
	int n, k, l = 500000;
	scanf("%d %d", &n, &k);
	if (n >= 1 && n <= l && k >= 1 && n <= l){
		int arr[n];
		int i, j, m, an, o, best_and = numeric_limits<int>::min();
		for (i = 0; i < n; i++){
			scanf("%d", &arr[i]);			
		}		
	        for (i = 0; i < n; i++){
			printf("Slice beginning at %d\n", i);
			j = i;
			an = numeric_limits<int>::max();	
			do {
				o = arr[j];
				for (m = 1; m < k; m++){
					printf("\t\tOr of %d and %d is %d\n", o, arr[(j + m)%n], o | arr[(j + m)%n]);
					o = o | arr[(j + m)%n];
				}
				printf("\tOr from %d to %d is %d\n", j, (j+m)%n, o);
				j = (j + m)%n;
				an = an & o;
			} while (j != i);
			printf("And is %d\n", an);
			if (an > best_and){	
				best_and = an;
			}
	        }
		printf("%d", best_and);
	}
        return 0;
}

