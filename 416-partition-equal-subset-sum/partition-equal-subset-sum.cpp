class Solution {
public:
    int dp[20005];
    bool f(vector<int>& nums,int i,int a){
        if(a<0) return false;
        if(a==0) return true;
        if(i==nums.size()-1) return nums[i]==a;
        if(dp[a]!=-1) return dp[a];
        return dp[a]=f(nums,i+1,a-nums[i]) || f(nums,i+1,a);
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        int c=0;
        for(int i=0;i<nums.size();i++){
            c+=nums[i];
        }
        if(c%2==1) return false;
        // return f(nums,0,c/2);

        vector<vector<bool>> dp(nums.size(),vector<bool>(c/2+1,false));
        for(int i=0;i<nums.size();i++){
            dp[i][0]==true;
        }
        if(nums[0]>c/2) return false;
        dp[0][nums[0]]=true;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=c/2;j++){
                dp[i][j]=dp[i-1][j];
                if(j-nums[i]>=0){
                    dp[i][j]=dp[i][j]||dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[nums.size()-1][c/2];
    }
};