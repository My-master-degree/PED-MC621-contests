#include<bits/stdc++.h>

using namespace std;

int main(){
	list<int> v{ 10, 20, 30, 40, 50 }; 
  
	// Print vector 
	cout << "Vector contains :"; 
	for (auto val : v) 
		cout << " " << val; 
	cout << "\n"; 

	list<int>::iterator low1, low2; 

	// std :: lower_bound 
	low1 =  lower_bound(v.begin(), v.end(), 20); 
	low2 =  lower_bound(v.begin(), v.end(), 55); 	
cout << "lower_bound at position " << low1 << '\n';
cout << "upper_bound at position " << low2 << '\n';

  
}
