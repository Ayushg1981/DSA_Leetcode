class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int ans=INT_MAX;
                for(int k=0;k<n;k++){
                    if(j!=k) ans=min(ans,matrix[i-1][k]);
                }
                matrix[i][j]+=ans;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,matrix[n-1][i]);
        }
        return ans;
    }
};