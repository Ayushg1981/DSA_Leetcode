class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int l=0;
        int r=n*m;
        vector<int> a(r);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[l++]=grid[i][j];
            }
        }
        sort(a.begin(),a.end());
        int x=a[r/2];
        int ans=0;
        for(int i=0;i<r;i++){
            if((x-a[i])%k!=0) return -1;
            ans+=abs(x-a[i])/k;
        }
        return ans;
    }
};