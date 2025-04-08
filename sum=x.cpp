#include <bits/stdc++.h>
using namespace std;

int main (){
	int n, x;
	cin >> n >> x;
	int A[n];
	for(int i=0; i<n; i++){
		cin >> A[i];
	}
	unordered_map<int, int> value;
	for(int i=0; i<n; i++){
		int target = x - A[i];
		
		if(value.count(target)){
			cout << value[target] + 1 << " " << i + 1 << endl;
			return 0;
		}
		
		value[A[i]] = i;
	}
	cout << "IMPOSSIBLE";
	return 0;
}
