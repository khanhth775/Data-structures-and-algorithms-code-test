#include <bits/stdc++.h>
using namespace std;

const int MAXN = 16;
const int MAXM = 5;

int N, M;
int A[MAXN][MAXN];
int c[MAXN];
int period[MAXN];
int load[MAXM];
int currMaxLoad = 0;
int bestLoad = INT_MAX;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
}

bool checkPrerequisites(int k, int v) {
    for (int j = 0; j < N; j++) {
        if (A[k][j] == 1 && period[j] != 0 && v >= period[j]) {
            return false;
        }
        if (A[j][k] == 1 && period[j] != 0 && period[j] >= v) {
            return false;
        }
    }
    return true;
}

void updateBest() {
    int maxLoad = 0;
    for (int i = 0; i < M; i++) {
        maxLoad = max(maxLoad, load[i]);
    }
    bestLoad = min(bestLoad, maxLoad);
}

void Try(int k) {
    if (k == N) {
        updateBest();
        return;
    }
    for (int v = 1; v <= M; v++) {
        if (checkPrerequisites(k, v)) {
            period[k] = v;
            int oldLoad = load[v - 1];
            load[v - 1] += c[k];
            int oldMaxLoad = currMaxLoad;
            currMaxLoad = max(currMaxLoad, load[v - 1]);
            if (currMaxLoad < bestLoad) {
                Try(k + 1);
            }
            load[v - 1] = oldLoad;
            period[k] = 0;
            currMaxLoad = oldMaxLoad;
        }
    }
}

int main() {
    input();
    memset(period, 0, sizeof(period));
    memset(load, 0, sizeof(load));
    Try(0);
    cout << bestLoad << endl;
    return 0;
}
