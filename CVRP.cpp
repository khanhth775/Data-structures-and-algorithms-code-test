#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;  // So khach hang toi da
const int MAXK = 10;  // So xe tai toi da

int n, K, Q;
int d[MAXN + 1];            // Nhu cau cua khach hang 1..n
int c[MAXN + 1][MAXN + 1];    // Ma tran khoang cach (0 la kho)
bool visited[MAXN + 1];     // Danh dau khach hang da duoc phuc vu
int load[MAXK];           // Tai trong hien tai cua moi xe
int route[MAXK][MAXN];    // Danh sach khach hang cua moi xe (theo thu tu phuc vu)
int routeSize[MAXK];      // So khach hang trong tuyen cua moi xe
int best = INT_MAX;       // Luu loi giai toi uu nho nhat
int curr = 0;             // Tong chi phi hien tai

// Ham nhap du lieu
void input(){
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            cin >> c[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    memset(load, 0, sizeof(load));
    memset(routeSize, 0, sizeof(routeSize));
}

// Ham tinh chi phi cua mot tuyen xe hien co
int calculateRouteCost(int k) {
    int cost = 0;
    if (routeSize[k] == 0) return 0;
    cost += c[0][route[k][0]]; // Tu kho den khach hang dau tien
    for (int i = 0; i < routeSize[k]-1; i++){
        cost += c[route[k][i]][route[k][i + 1]];
    }
    cost += c[route[k][routeSize[k] - 1]][0]; // Tu khach hang cuoi ve kho
    return cost;
}

// Cap nhat loi giai tot nhat hien co
void updateBest(){
    int total = 0;
    for (int k = 0; k < K; k++){
        total += calculateRouteCost(k);
    }
    best = min(best, total);
}

// Ham Try: chon khach hang tiep theo (chua phuc vu) va thu chen vao tuyen cua tung xe tai moi vi tri
void Try(){
    // Neu tat ca khach hang da duoc phuc vu, cap nhat loi giai
    bool allVisited = true;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            allVisited = false;
            break;
        }
    }
    if (allVisited) {
        updateBest();
        return;
    }
    
    // Chon khach hang chua phuc vu dau tien (theo thu tu so)
    int cust = -1;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cust = i;
            break;
        }
    }
    if (cust == -1) return;
    
    // Thu gan khach hang cust cho tung xe, voi moi vi tri chen co the
    for (int k = 0; k < K; k++){
        if (load[k] + d[cust] <= Q) {
            // Thu chen tai cac vi tri tu 0 den routeSize[k]
            for (int pos = 0; pos <= routeSize[k]; pos++){
                // Tinh chen lech chi phi khi chen khach hang cust vao vi tri pos
                int addCost = 0, removedCost = 0;
                if (routeSize[k] == 0) {
                    // Neu xe chua co khach hang, chi phi la tu kho den cust va cust ve kho
                    addCost = c[0][cust] + c[cust][0];
                } else if (pos == 0) {
                    // Chen o dau: thay doi doan tu kho den khach hang dau ban dau
                    removedCost = c[0][route[k][0]];
                    addCost = c[0][cust] + c[cust][route[k][0]];
                } else if (pos == routeSize[k]) {
                    // Chen o cuoi: thay doi doan tu khach hang cuoi sang kho
                    removedCost = c[route[k][routeSize[k] - 1]][0];
                    addCost = c[route[k][routeSize[k] - 1]][cust] + c[cust][0];
                } else {
                    // Chen giua: thay doi doan tu khach hang truoc den sau
                    removedCost = c[route[k][pos-1]][route[k][pos]];
                    addCost = c[route[k][pos-1]][cust] + c[cust][route[k][pos]];
                }
                int diff = addCost - removedCost;
                
                // Cap nhat trang thai
                // Dich chuyen cac phan tu sau vi tri chen sang phai
                for (int j = routeSize[k]; j > pos; j--){
                    route[k][j] = route[k][j-1];
                }
                route[k][pos] = cust;
                routeSize[k]++;
                load[k] += d[cust];
                curr += diff;
                visited[cust] = true;
                
                // Cat nhanh neu chi phi tam thoi khong hua hen
                if (curr < best)
                    Try();
                
                // Quay lui: hoan nguyen cac thay doi
                visited[cust] = false;
                load[k] -= d[cust];
                curr -= diff;
                routeSize[k]--;
                for (int j = pos; j < routeSize[k]; j++){
                    route[k][j] = route[k][j + 1];
                }
            }
        }
    }
}

int main(){
    input();
    Try();
    cout << best << endl;
    return 0;
}

