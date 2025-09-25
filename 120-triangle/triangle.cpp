class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int x=2;
        for(int i=1;i<n;i++){
            for(int j=0;j<x;j++){
                if((j-1)>=0 && (j)<(x-1)) triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
                else if((j-1)>=0) triangle[i][j]+=triangle[i-1][j-1];
                else triangle[i][j]+=triangle[i-1][j];
            }
            x++;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,triangle[n-1][i]);
        }
        return ans;
    }
};