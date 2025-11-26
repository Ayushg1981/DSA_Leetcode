class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,0)));
        int x=0;
        for(int i=0;i<n;i++){
            x+=grid[i][0];
            x=x%k;
            dp[i][0][x]=1;
        }
        x=0;
        for(int i=0;i<m;i++){
            x+=grid[0][i];
            x=x%k;
            dp[0][i][x]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                for(int l=0;l<k;l++){
                    dp[i][j][(l+grid[i][j])%k]=(dp[i][j][(l+grid[i][j])%k]+dp[i-1][j][l])%1000000007;
                    dp[i][j][(l+grid[i][j])%k]=(dp[i][j][(l+grid[i][j])%k]+dp[i][j-1][l])%1000000007;    
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};