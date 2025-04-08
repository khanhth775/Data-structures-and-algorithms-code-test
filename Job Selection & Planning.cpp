#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int d[MAXN], p[MAXN];
int times[MAXN];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> d[i] >> p[i];
    }
    memset(times, -1, sizeof(times));  

    pair<int, int> jobs[MAXN];  
    for (int i = 0; i < n; i++){
        jobs[i] = {p[i], d[i]};
    }
    sort(jobs, jobs + n, greater<pair<int, int>>());  

    int total = 0;
    for (int i = 0; i < n; i++){
        int profit = jobs[i].first;
        int deadline = jobs[i].second;
        for (int j = deadline; j >= 1; j--){
            if (times[j] == -1){
                times[j] = 1;
                total += profit;
                break;
            }
        }
    }
    cout << total << endl;

    return 0;
}

