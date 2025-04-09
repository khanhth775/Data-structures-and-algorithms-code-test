#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
int a[MAXN];
int temp[MAXN];
long long Q = 0;

void mergeSort(int l, int r){
    if (l >= r) return; 

    int mid = l + (r - l) / 2;
    mergeSort(l, mid);         
    mergeSort(mid + 1, r);     

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r){
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            Q = (Q + (mid - i + 1)) % MOD; 
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = temp[i];
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    mergeSort(0, n-1);
    cout << Q << endl;
    return 0;
}
