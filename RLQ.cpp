#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
int n, A[maxN], g[maxN][22];

int getMax(int l, int r){
    int k=log2(r-l+1);
    return max(g[l][k], g[r-(1<<k)+1][k]);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i];
        g[i][0] = A[i];
    }
    for(int j=1; (1<<j)<=n; j++){
        for(int i=0; i+(1<<j)<=n; i++){
            g[i][j] = max(g[i][j-1], g[i+(1<<j-1)][j-1]);
        }
    }
    int m;
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        cout << getMax(l, r) << endl;
    }
    return 0;
}

