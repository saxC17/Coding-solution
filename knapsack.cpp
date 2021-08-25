int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    vector<vector<int>>dp(C + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= n; j++) {
            if (B[j - 1] <= i) {
                dp[i][j] = A[j - 1] + dp[i - B[j - 1]][j - 1];

            }
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);

        }
    }
    return dp[C][n];
}
