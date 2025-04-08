#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int d[MAXN];

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> d[i];
    }
    sort(d, d+n, greater<int>());
    int T = 0;
    for(int i=0; i<n; i++){
        int finish = i + d[i]; 
        T = max(T, finish);    
    }
    cout << T << endl;
    return 0;
}

