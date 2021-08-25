class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		// sort(coins.begin(),coins.end());
		int n = coins.size();
		vector<vector<int>>dp(amount + 1, vector<int>(n, 0));
		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = INT_MAX;
				if (j > 0)
					dp[i][j] = dp[i][j - 1];
				if (i >= coins[j] && dp[i - coins[j]][j] != INT_MAX) {
					dp[i][j] = min(1 + dp[i - coins[j]][j], dp[i][j]);
				}
			}
		}
		if (dp[amount][n - 1] == INT_MAX) {
			return -1;
		}
		return dp[amount][n - 1];

	}
};