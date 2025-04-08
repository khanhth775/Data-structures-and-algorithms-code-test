#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int a[MAXN];
int dp[MAXN][2]; // 0 la le, 1 la chan
int res = INT_MIN;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    dp[0][0] = (a[0] % 2 == 0 ? INT_MIN : a[0]);
    dp[0][1] = (a[0] % 2 == 0 ? a[0] : INT_MIN);
    if(dp[0][1] > res) res = dp[0][1];

	for(int i=1; i<n; i++){
	    dp[i][0] = dp[i][1] = INT_MIN; 
	    if (a[i] % 2 == 0){
	        dp[i][1] = max(a[i], (dp[i-1][1] != INT_MIN ? dp[i-1][1] + a[i] : INT_MIN));
	        dp[i][0] = (dp[i-1][0] != INT_MIN ? dp[i-1][0] + a[i] : INT_MIN);
	    } else {
	        dp[i][0] = max(a[i], (dp[i-1][0] != INT_MIN ? dp[i-1][0] + a[i] : INT_MIN));
	        dp[i][1] = (dp[i-1][1] != INT_MIN ? dp[i-1][1] + a[i] : INT_MIN);
	    }
	    if (dp[i][1] > res) res = dp[i][1];
	}

    
    if(res == INT_MIN){
        cout << "NOT_FOUND" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}

