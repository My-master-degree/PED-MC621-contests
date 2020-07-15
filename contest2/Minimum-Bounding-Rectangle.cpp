#include<bits/stdc++.h>
#define MAX_COORDINATE 2000000000

#define RB pair<pair<int, int>, pair<int, int> >

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	if (t > 0 && t < 100){
		list<RB> outputs;
		pair<int, int> lic, rsc, p1, p2;	
		int n, r;
		char o;
		while (t--){	
			scanf("%d", &n);
			if (n > 0 && n < 100){
				lic.first = lic.second = MAX_COORDINATE;
				rsc.first = rsc.second = -MAX_COORDINATE;
				while (n--){
					cin>>o;
					if (o == 'p'){
						scanf("%d %d", &p1.first, &p1.second);
						if (p1.first > rsc.first)
							rsc.first = p1.first;
						if (p1.first < lic.first)
							lic.first = p1.first;
						if (p1.second > rsc.second)
							rsc.second = p1.second;
						if (p1.second < lic.second)
							lic.second = p1.second;
					}else if (o == 'c'){
						scanf("%d %d %d", &p1.first, &p1.second, &r);
						if (p1.first + r > rsc.first)
							rsc.first = p1.first + r;
						if (p1.first - r < lic.first)
							lic.first = p1.first - r;
						if (p1.second + r > rsc.second)
							rsc.second = p1.second + r;
						if (p1.second - r < lic.second)
							lic.second = p1.second - r;
					}else if (o == 'l'){
						scanf("%d %d %d %d", &p1.first, &p1.second, &p2.first, &p2.second);
						if (p1.first > rsc.first)
							rsc.first = p1.first;
						if (p1.first < lic.first)
							lic.first = p1.first;
						if (p1.second > rsc.second)
							rsc.second = p1.second;
						if (p1.second < lic.second)
							lic.second = p1.second;

						if (p2.first > rsc.first)
							rsc.first = p2.first;
						if (p2.first < lic.first)
							lic.first = p2.first;
						if (p2.second > rsc.second)
							rsc.second = p2.second;
						if (p2.second < lic.second)
							lic.second = p2.second;
					}
				}
				outputs.push_back(make_pair(lic, rsc));
			}
		}
		for (list<RB>::iterator it = outputs.begin(); it != outputs.end(); ++it){
			printf("%d %d %d %d\n", (*it).first.first, (*it).first.second, (*it).second.first, (*it).second.second);
		}
	}
	return 0;
}
