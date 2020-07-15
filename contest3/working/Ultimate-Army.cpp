#include<bits/stdc++.h>

using namespace std;

void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 

int main(){
	int n;
	scanf("%d", &n);
	if (n >= 1){
		char a[1000000];
		int i, j = 0, t;
		stack<int> s;
		map<int, int> m;
		char buff[1000];
		scanf("%s", a);
		for (i = 0; a[i] != '\0'; i++){
			//printf("In %c\n", a[i]);
			if (a[i] >= '0' && a[i] <= '9'){
				buff[j] = a[i];
				j++;
			}else{
				if (j > 0){
					buff[j] = '\0';
					j = 0;
					s.push(atoi(buff));
				}
				if (a[i] == ')'){
					//showstack(s);
					t = s.top();
					s.pop();
					m[t] = s.top();
				}
			}
		}
		if (j > 0){
			buff[j] = '\0';
			m[atoi(buff)] = 0;
		}else{
			m[s.top()] = 0;
		}
		for (i = 1; i <= n; i++){
			printf("%d ", m[i]);
		}
	}
	return 0;
}
