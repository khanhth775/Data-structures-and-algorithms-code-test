#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
const int INF = 1e9;

int n, m;
vector<int> maxVal(4*maxN);
vector<int> A(maxN);

void build(int id, int l, int r){
    if(l == r){
        maxVal[id] = A[l];
        return;
    }
    int mid=(l+r)/2;
    int LC=2*id, RC=2*id+1;
    build(LC, l, mid);
    build(RC, mid+1, r);
    maxVal[id] = max(maxVal[LC], maxVal[RC]);
}

int getMaxFromNode(int id, int l, int r, int i, int j){
    if (i>r || j<l) return -INF;
    if (i<=l && j>=r) return maxVal[id];
    int mid=(l+r)/2;
    int LC=2*id, RC=2*id+1;
    int maxLeft = getMaxFromNode(LC, l, mid, i, j);
    int maxRight = getMaxFromNode(RC, mid+1, r, i, j);
    return max(maxLeft, maxRight);
}

int getMax(int i, int j){
    return getMaxFromNode(1, 1, n, i, j);
}

void updateFromNode(int id, int l, int r, int index, int value){
    if (l>r || index<l || index>r) return;
    if (l == r) {
        maxVal[id] = value;
        return;
    }
    int mid=(l+r)/2;
    int LC=2*id, RC=2*id+1;
    updateFromNode(LC, l, mid, index, value);
    updateFromNode(RC, mid+1, r, index, value);
    maxVal[id] = max(maxVal[LC], maxVal[RC]);
}

void update(int i, int v){
    updateFromNode(1, 1, n, i, v);
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }
    build(1, 1, n);
    cin >> m;
    while (m--){
        string command;
        cin >> command;
        if (command == "get-max"){
            int i, j;
            cin >> i >> j;
            cout << getMax(i, j) << endl;
        } else if (command == "update"){
            int i, v;
            cin >> i >> v;
            update(i, v);
        }
    }
    return 0;
}
