class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> a(n,vector<int>(m,1)),b(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0 && i==0) continue;
                if(j==0) a[i][j]=(a[i-1][m-1]*(long long)grid[i-1][m-1])%12345;
                else a[i][j]=(a[i][j-1]*(long long)grid[i][j-1])%12345;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(j==m-1 && i==n-1) continue;
                if(j==m-1){
                    b[i][j]=(b[i+1][0]*(long long)grid[i+1][0])%12345;
                    a[i][j]=(a[i][j]*(long long)b[i][j])%12345;
                }
                else{
                    b[i][j]=(b[i][j+1]*(long long)grid[i][j+1])%12345;
                    a[i][j]=(a[i][j]*(long long)b[i][j])%12345;
                }
            }
        }
        return a;
    }
};