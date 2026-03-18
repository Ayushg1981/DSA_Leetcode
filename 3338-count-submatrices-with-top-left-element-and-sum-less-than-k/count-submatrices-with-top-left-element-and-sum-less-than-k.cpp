class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans=0;
        if(grid[0][0]<=k) ans++;
        for(int i=1;i<grid.size();i++){
            grid[i][0]+=grid[i-1][0];
            if(grid[i][0]<=k) ans++;
        }
        for(int i=1;i<grid[0].size();i++){
            grid[0][i]+=grid[0][i-1];
            if(grid[0][i]<=k) ans++;
        }
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                grid[i][j]=grid[i][j]+grid[i][j-1]+grid[i-1][j]-grid[i-1][j-1];
                if(grid[i][j]<=k) ans++;
            }
        }
        return ans;
    }
};