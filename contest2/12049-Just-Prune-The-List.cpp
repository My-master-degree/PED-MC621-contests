#include <stdio.h>
#include <map>
#include <list>

using namespace std;

int main()
{
	short t;
	scanf("%hd", &t);
	if (t >= 1 && t <= 100){
		list<int> outputs;
		while (t--){
			short n, m;
			scanf("%hd %hd", &n, &m);
			if (n >= 1 && n <= 10000 && m >= 1 && m <= 10000){
				map<int, int> m1, m2;
				int buff;
				map<int, int>::iterator it;
				//first list
				while (n--){
					scanf("%d", &buff);
					it = m1.find(buff);
					if (it != m1.end())
						it->second = it->second + 1;	
					else
						m1.insert(make_pair(buff, 1));
				}
				//second list
				while (m--){
					scanf("%d", &buff);
					//decrement from map 1
					it = m1.find(buff);
					if (it != m1.end()){
						it->second = it->second - 1;	
						if (it->second == 0)
							m1.erase(it->first);
					}else{
						//increment in map 2
						it = m2.find(buff);
						if (it != m2.end())
							it->second = it->second + 1;	
						else
							m2.insert(make_pair(buff, 1));
					}
				}
/*
				printf("\n================\n");
				for (it = m1.begin(); it != m1.end(); ++it){
					printf("%d|%d ", it->first, it->second);
				}
				printf("\n");
				for (it = m2.begin(); it != m2.end(); ++it){
					printf("%d|%d ", it->first, it->second);
				}
				printf("\n");
*/
				int c = 0;
				for (it = m1.begin(); it != m1.end(); it++) 
					c += it->second;
				for (it = m2.begin(); it != m2.end(); it++)
					c += it->second;
			
				
				outputs.push_back(c);
			}
		}
		for (list<int>::iterator it = outputs.begin(); it != outputs.end(); ++it){
			printf("%d\n", *it);
		}
	}
	return 0;
}

