class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        int NEG = -1e9;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(3,NEG)));
        for(int k = 0; k < 3; k++) {
            if (coins[0][0] >= 0)
                dp[0][0][k] = coins[0][0];
            else {
                if (k > 0)
                    dp[0][0][k] = 0;
                else
                    dp[0][0][k] = coins[0][0];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) continue;
                for(int k = 0; k < 3; k++) {
                    int best = NEG;
                    if(i > 0) best = max(best, dp[i-1][j][k]);
                    if(j > 0) best = max(best, dp[i][j-1][k]);
                    if(best == NEG) continue;
                    dp[i][j][k] = max(dp[i][j][k], best + coins[i][j]);
                    if(coins[i][j] < 0 && k > 0) {
                        int best2 = NEG;
                        if(i > 0) best2 = max(best2, dp[i-1][j][k-1]);
                        if(j > 0) best2 = max(best2, dp[i][j-1][k-1]);
                        if(best2 != NEG) dp[i][j][k] = max(dp[i][j][k], best2);
                    }
                }
            }
        }

        return max({dp[n-1][m-1][0], dp[n-1][m-1][1], dp[n-1][m-1][2]});
    }
};