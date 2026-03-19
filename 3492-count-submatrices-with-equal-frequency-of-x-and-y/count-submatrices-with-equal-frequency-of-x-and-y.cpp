class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> v(n+1,vector<int>(m+1,0));
        vector<vector<bool>> flag(n+1,vector<bool>(m+1,false));
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(grid[i-1][j-1]=='X'){
                    v[i][j]++;
                    flag[i][j]=true;
                }
                else if(grid[i-1][j-1]=='Y') v[i][j]--;
                flag[i][j]=(flag[i][j]|flag[i-1][j])|flag[i][j-1];
                v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
                if(v[i][j]==0 && flag[i][j]) ans++;
            }
        }
        return ans;
    }
};