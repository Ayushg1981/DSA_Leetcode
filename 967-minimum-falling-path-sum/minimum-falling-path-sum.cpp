class Solution {
public:
    bool isValid(int j,int n){
        return j>=0 && j<n;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int ans=matrix[i-1][j];
                if(isValid(j-1,n)) ans=min(ans,matrix[i-1][j-1]);
                if(isValid(j+1,n)) ans=min(ans,matrix[i-1][j+1]);
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