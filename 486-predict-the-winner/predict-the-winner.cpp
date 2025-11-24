class Solution {
public:
    int dp[25][25];
    int f(int i,int j,vector<int>& nums){
        if(j==i) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=max(nums[i]-f(i+1,j,nums),nums[j]-f(i,j-1,nums));
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return (f(0,nums.size()-1,nums)>=0);
    }
};