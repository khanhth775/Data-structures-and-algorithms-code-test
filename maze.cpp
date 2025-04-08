#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
const int INF = 1e7;

// C?u trúc luu t?a d? ô trong mê cung
struct Cell {
    int x, y;
};

int a[MAX_N][MAX_N]; // Ma tr?n bi?u di?n mê cung
int d[MAX_N][MAX_N]; // Ma tr?n luu s? bu?c d?n t?ng ô
int dx[] = {1, 0, -1, 0}; // Di chuy?n d?c (xu?ng, lên)
int dy[] = {0, 1, 0, -1}; // Di chuy?n ngang (ph?i, trái)
int n, m, r, c; // Kích thu?c mê cung và v? trí xu?t phát

int solve() {
    queue<Cell> q;
    q.push({r, c}); // Thêm ô xu?t phát vào hàng d?i
    d[r][c] = 0;    // S? bu?c t?i ô xu?t phát là 0
    a[r][c] = 1;    // Ðánh d?u ô xu?t phát dã du?c tham

    while (!q.empty()) {
        Cell u = q.front(); // L?y ô ? d?u hàng d?i
        q.pop();
        for (int i = 0; i < 4; i++) { // Duy?t 4 hu?ng
            int x = u.x + dx[i], y = u.y + dy[i]; // T?a d? ô lân c?n
            if (x < 1 || x > n || y < 1 || y > m) { // N?u ô n?m ngoài biên
                return d[u.x][u.y] + 1; // Tr? v? s? bu?c c?n d? thoát
            }
            if (a[x][y] == 0) { // N?u ô lân c?n là ô tr?ng
                d[x][y] = d[u.x][u.y] + 1; // C?p nh?t s? bu?c
                q.push({x, y}); // Thêm ô lân c?n vào hàng d?i
                a[x][y] = 1; // Ðánh d?u ô dã du?c tham
            }
        }
    }
    return -1; // Không tìm th?y du?ng thoát
}

int main() {
    cin >> n >> m >> r >> c; // Nh?p kích thu?c mê cung và v? trí xu?t phát
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j]; // Nh?p ma tr?n mê cung
        }
    }
    cout << solve() << endl; // In ra s? bu?c ng?n nh?t ho?c -1 n?u không có du?ng thoát
    return 0;
}

