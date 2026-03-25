class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<long long> a(n,0),b(m,0);
        long long totalSum=0;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
            a[i]=sum;
            if(i>0) a[i]+=a[i-1];
            totalSum+=sum;
        }
        for(int j=0;j<m;j++){
            long long sum=0;
            for(int i=0;i<n;i++){
                sum+=grid[i][j];
            }
            b[j]=sum;
            if(j>0) b[j]+=b[j-1];
        }
        if(totalSum%2==1) return false;
        for(int i=0;i<n;i++){
            if(totalSum/2==a[i]) return true;
        }
        for(int i=0;i<m;i++){
            if(totalSum/2==b[i]) return true;
        }
        return false;
    }
};