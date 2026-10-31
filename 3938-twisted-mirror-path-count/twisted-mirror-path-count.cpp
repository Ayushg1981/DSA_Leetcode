class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<pair<int,int>>> v(n,vector<pair<int,int>> (m,{0,0}));
        v[0][0].first=1;
        for(int i=1;i<n;i++){
            if(grid[i][0]==0){
                v[i][0].first=v[i-1][0].first;
            }
            else{
                v[i][0].first=v[i-1][0].first;
                break;
            }
        }
        for(int i=1;i<m;i++){
            if(grid[0][i]==0){
                v[0][i].first=v[0][i-1].first;
            }
            else{
                if(1<n) v[0][i].second=v[0][i-1].first;
                break;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==1){
                    if(grid[i-1][j]==1){
                        v[i][j].first+=v[i-1][j].second;
                    }
                    else{
                        v[i][j].first+=v[i-1][j].first;
                    }
                    v[i][j].second+=v[i][j-1].first;
                    // if(grid[i][j-1]==1){
                    //     v[i][j].second+=v[i][j-1].first;
                    // }
                    // else{
                    //     v[i][j].second+=v[i][j-1].first;
                    // }
                }
                else{
                    if(grid[i-1][j]==1){
                        v[i][j].first+=v[i-1][j].second;
                    }
                    else{
                        v[i][j].first+=v[i-1][j].first;
                    }
                    v[i][j].first+=v[i][j-1].first;
                    // if(grid[i][j-1]==1){
                    //     v[i][j].first+=v[i][j-1].first;
                    // }
                    // else{
                    //     v[i][j].first+=v[i][j-1].first;
                    // }
                }
                v[i][j].first=v[i][j].first%1000000007;
                v[i][j].second=v[i][j].second%1000000007;
            }
        }
        return v[n-1][m-1].first;
    }
};