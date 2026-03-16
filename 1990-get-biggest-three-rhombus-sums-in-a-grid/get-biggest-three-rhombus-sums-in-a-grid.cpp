class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> a(m,vector<int>(n,0)),b(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            int k=i+1;
            a[0][i]=grid[0][i];
            for(int j=1;j<m && k<n;j++,k++){
                a[j][k]=grid[j][k]+a[j-1][k-1];
            }
        }
        for(int i=0;i<m;i++){
            int k=i+2;
            if(i+1<m) a[i+1][0]=grid[i+1][0];
            for(int j=1;j<n && k<m;j++,k++){
                a[k][j]=grid[k][j]+a[k-1][j-1];
            }
        }
        for(int i=n-1;i>=0;i--){
            int k=i-1;
            b[0][i]=grid[0][i];
            for(int j=1;j<m && k>=0;j++,k--){
                b[j][k]=grid[j][k]+b[j-1][k+1];
            }
        }
        for(int i=0;i<m;i++){
            int k=i+2;
            if(i+1<m) b[i+1][n-1]=grid[i+1][n-1];
            for(int j=n-2;j>=0 && k<m;j--,k++){
                b[k][j]=grid[k][j]+b[k-1][j+1];
            }
        }
        int maxR=min(n,m)/2+min(n,m)%2;
        set<int> s;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                s.insert(grid[i][j]);
                for(int k=1;k<=maxR;k++){
                    if(j-k>=0 && j+k<n && i-2*k>=0){
                        int x=0;
                        if(j-k==0) x+=a[i][j];
                        else x+=a[i][j]-a[i-k-1][j-k-1];
                        if(i-2*k==0) x+=a[i-k][j+k];
                        else x+=a[i-k][j+k]-a[i-2*k-1][j-1];
                        x+=b[i-1][j+1]-b[i-k][j+k];
                        x+=b[i-k-1][j-k+1]-b[i-2*k][j];
                        s.insert(x);
                    }
                }
            }
        }
        int count = 0;
        vector<int> ans;
        for (auto it = s.rbegin(); it != s.rend() && count < 3; ++it, ++count) {
            ans.push_back(*it);
        }
        return ans;
    }
};