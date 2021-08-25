#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n ; cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = INT_MIN;
    vector<int>dp(n, 0LL);
    for (int i = 0; i < n; i++) {
        dp[i] = v[i];
        for (int j = i - 1; j >= 0; j--) {
            if (v[j] <= v[i]) {
                dp[i] = max(dp[i], v[i] + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}