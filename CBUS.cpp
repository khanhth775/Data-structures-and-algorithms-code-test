#include <bits/stdc++.h>
using namespace std;

int n, k;
int c[25][25];
int x[25];
bool visited[25];
int load = 0, f = 0;
int c_min = INT_MAX;
int f_min = INT_MAX;

void input(){
    cin >> n >> k;
    for (int i = 0; i <= 2 * n; i++){
        for (int j = 0; j <= 2 * n; j++){
            cin >> c[i][j];
            if (i != j) c_min = min(c_min, c[i][j]);
        }
    }
}

void Try(int i){
    for (int v = 1; v <= 2 * n; v++){
        if (!visited[v] && (v > n || load + 1 <= k) && (v <= n || visited[v - n])){
            x[i] = v;
            visited[v] = true;
            f += c[x[i - 1]][v];
            if (v <= n) load++;
            else load--;

            if (i == 2 * n){
                f_min = min(f_min, f + c[v][0]);
            } else if (f + c_min * (2 * n - i + 1) < f_min){
                Try(i + 1);
            }

            if (v <= n) load--;
            else load++;
            f -= c[x[i - 1]][v];
            visited[v] = false;
        }
    }
}

int main(){
    input();
    x[0] = 0;
    Try(1);
    cout << f_min << endl;
    return 0;
}

