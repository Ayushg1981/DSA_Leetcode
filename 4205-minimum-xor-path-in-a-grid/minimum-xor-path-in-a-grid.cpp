class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<bool>>> dp(n,vector<vector<bool>> (m,vector<bool> (1024, false)));
        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                for (int k = 0; k < 1024; k++) {
                    int prev = k ^ grid[i][j];
                    if (i > 0 && dp[i - 1][j][prev]) dp[i][j][k] = true;
                    if (j > 0 && dp[i][j - 1][prev]) dp[i][j][k] = true;
                }
            }
        }

        for (int k = 0; k < 1024; k++) {
            if (dp[n - 1][m - 1][k]) return k;
        }
        return -1;
    }
};