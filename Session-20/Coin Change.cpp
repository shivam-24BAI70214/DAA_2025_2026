class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        vector<int> dp(sum + 1, INT_MAX);
        dp[0]=0;
        for (int i=1;i<=sum;i++) {
            for (int coin : coins) {
                if (coin<=i && dp[i-coin]!=INT_MAX) {
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        if (dp[sum] == INT_MAX) return -1;
        return dp[sum];
    }
};
