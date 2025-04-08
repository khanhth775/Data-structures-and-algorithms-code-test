#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
const int INF = 1e7;

// C?u tr�c luu t?a d? � trong m� cung
struct Cell {
    int x, y;
};

int a[MAX_N][MAX_N]; // Ma tr?n bi?u di?n m� cung
int d[MAX_N][MAX_N]; // Ma tr?n luu s? bu?c d?n t?ng �
int dx[] = {1, 0, -1, 0}; // Di chuy?n d?c (xu?ng, l�n)
int dy[] = {0, 1, 0, -1}; // Di chuy?n ngang (ph?i, tr�i)
int n, m, r, c; // K�ch thu?c m� cung v� v? tr� xu?t ph�t

int solve() {
    queue<Cell> q;
    q.push({r, c}); // Th�m � xu?t ph�t v�o h�ng d?i
    d[r][c] = 0;    // S? bu?c t?i � xu?t ph�t l� 0
    a[r][c] = 1;    // ��nh d?u � xu?t ph�t d� du?c tham

    while (!q.empty()) {
        Cell u = q.front(); // L?y � ? d?u h�ng d?i
        q.pop();
        for (int i = 0; i < 4; i++) { // Duy?t 4 hu?ng
            int x = u.x + dx[i], y = u.y + dy[i]; // T?a d? � l�n c?n
            if (x < 1 || x > n || y < 1 || y > m) { // N?u � n?m ngo�i bi�n
                return d[u.x][u.y] + 1; // Tr? v? s? bu?c c?n d? tho�t
            }
            if (a[x][y] == 0) { // N?u � l�n c?n l� � tr?ng
                d[x][y] = d[u.x][u.y] + 1; // C?p nh?t s? bu?c
                q.push({x, y}); // Th�m � l�n c?n v�o h�ng d?i
                a[x][y] = 1; // ��nh d?u � d� du?c tham
            }
        }
    }
    return -1; // Kh�ng t�m th?y du?ng tho�t
}

int main() {
    cin >> n >> m >> r >> c; // Nh?p k�ch thu?c m� cung v� v? tr� xu?t ph�t
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j]; // Nh?p ma tr?n m� cung
        }
    }
    cout << solve() << endl; // In ra s? bu?c ng?n nh?t ho?c -1 n?u kh�ng c� du?ng tho�t
    return 0;
}

