#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 1;
int n, A[maxN], f[maxN][22];

// Ham tra ve gia tri nho nhat trong doan [l, r] su dung Sparse Table
int minValue(int l, int r) {
    int k = log2(r - l + 1); // Do dai cua doan [l, r] de tinh muc log
    return min(f[l][k], f[r - (1 << k) + 1][k]); // Tra ve gia tri nho nhat cua hai doan con chong len nhau
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
        f[i][0] = A[i]; // Khoi tao Sparse Table muc 0 voi gia tri goc
    }

    // Xay dung Sparse Table
    for (int j = 1; (1 << j) <= n; j++) { // Xet cac muc log tu 1 den log2(n)
        for (int i = 0; i + (1 << j) <= n; i++) { // Xet tat ca cac doan co do dai 2^j
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]); 
            // Tinh gia tri nho nhat cua doan bang hai doan con co do dai 2^(j-1)
        }
    }

    int m;
    cin >> m; 
    long long Q = 0; 
    while (m--) {
        int l, r;
        cin >> l >> r; 
        Q += minValue(l, r); 
    }
    cout << Q << endl; 
    return 0;
}

