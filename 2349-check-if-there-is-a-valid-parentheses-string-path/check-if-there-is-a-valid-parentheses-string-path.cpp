class Solution {
public:
    int dp[101][101][101];
    bool f(int i,int j,int c,vector<vector<char>>& grid){
        if(c>99) return false;
        if(i>=grid.size() || j>=grid[0].size()) return false;
        if(i==grid.size()-1 && j==grid[0].size()-1){
            if(grid[i][j]==')' && c==1) return true;
            else return false;
        }
        if(dp[i][j][c]!=-1) return dp[i][j][c];

        if(grid[i][j]=='(') return dp[i][j][c]=(f(i+1,j,c+1,grid) || f(i,j+1,c+1,grid));
        else{
            if(c==0) return dp[i][j][c]=false;
            return dp[i][j][c]=(f(i+1,j,c-1,grid) || f(i,j+1,c-1,grid));
        }
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp,-1,sizeof (dp));
        if(grid[0][0]==')') return false;
        return f(1,0,1,grid) || f(0,1,1,grid);
    }
};