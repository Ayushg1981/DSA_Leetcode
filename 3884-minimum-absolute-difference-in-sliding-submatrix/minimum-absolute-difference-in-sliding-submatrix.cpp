class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1));
        
        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                set<int>s;
                for(int r=i;r<i+k;r++){
                    for(int c=j;c<j+k;c++){
                        s.insert(grid[r][c]);
                    }
                }
                if(s.size()<=1) ans[i][j]=0;
                else{
                    vector<int> v(s.begin(), s.end());        
                    sort(v.begin(),v.end());
                    int q=INT_MAX;
                    for(int u=1;u<v.size();u++){
                        if(v[u]!=v[u-1]){
                            q=min(q,abs(v[u]-v[u-1]));
                        }
                        else{
                            q=0;    
                        }
                    }
                    ans[i][j]=q==INT_MAX?0:q;
                }
            }
        }
        return ans;
    }
};