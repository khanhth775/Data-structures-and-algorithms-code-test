#include <bits/stdc++.h>
using namespace std;

const int MAX = 10; // Kich thuoc toi da cua tam phoi
int H, W, n; // H: chieu cao, W: chieu rong cua phoi, n: so luong hinh chu nhat can cat
int h[MAX + 1], w[MAX + 1]; // h[k], w[k]: kich thuoc cua hinh chu nhat thu k
bool mark[MAX + 1][MAX + 1]; // Danh dau o da bi chiem tren phoi

bool check(int vo, int vx, int vy, int k) {
    int wk = w[k], hk = h[k];
    if (vo == 1) swap(wk, hk); // Neu xoay 90 do, hoan doi chieu rong va chieu cao
    if (vx + wk > W || vy + hk > H) return false; // Kiem tra vuot ra khoi phoi
    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j < vy + hk; j++) {
            if (mark[i][j]) return false; // O da bi chiem, khong the dat
        }
    }
    return true; // Co the dat hinh chu nhat tai vi tri nay
}

void doMark(int vo, int vx, int vy, int k, bool state) {
    int wk = w[k], hk = h[k];
    if (vo == 1) swap(wk, hk); // Neu xoay 90 do, hoan doi chieu rong va chieu cao
    for (int i = vx; i < vx + wk; i++) {
        for (int j = vy; j < vy + hk; j++) {
            mark[i][j] = state; // Danh dau hoac xoa dau (state = true: danh dau, false: xoa dau)
        }
    }
}

bool found = false; // Co de kiem tra da tim duoc cach cat hop le

void Try(int k) {
    if (found) return; // Neu da tim duoc cach cat, khong tim tiep
    for (int vo = 0; vo <= 1; vo++) { // Trang thai xoay (0: khong xoay, 1: xoay 90 do)
        for (int vx = 0; vx <= W - w[k]; vx++) { // Thu tat ca vi tri theo chieu ngang
            for (int vy = 0; vy <= H - h[k]; vy++) { // Thu tat ca vi tri theo chieu doc
                if (check(vo, vx, vy, k)) { // Neu co the dat hinh chu nhat
                    doMark(vo, vx, vy, k, true); // Danh dau vung bi chiem
                    if (k == n) {
                        found = true; // Dat het n hinh chu nhat, tim duoc loi giai
                    } else {
                        Try(k + 1); // Goi de quy xu ly hinh chu nhat tiep theo
                    }
                    doMark(vo, vx, vy, k, false); // Xoa dau khi quay lai buoc truoc
                }
            }
        }
    }
}

int main() {
    cin >> H >> W; // Kich thuoc phoi
    cin >> n; // So luong hinh chu nhat can cat
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> w[i]; // Nhap chieu cao va chieu rong cua moi hinh chu nhat
    }
    memset(mark, false, sizeof(mark)); // Khoi tao tat ca o tren phoi la chua bi chiem
    Try(1); // Bat dau tim cach cat tu hinh chu nhat dau tien
    cout << (found ? 1 : 0) << endl; // Xuat ket qua (1: co the cat, 0: khong the cat)
    return 0;
}

