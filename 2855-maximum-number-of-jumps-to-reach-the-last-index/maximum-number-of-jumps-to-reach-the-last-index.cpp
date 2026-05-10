class Solution {
public:
    int maximumJumps(vector<int>& nums, int t) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            if(dp[i]>=0){
            for(int j=i+1;j<n;j++){
                if((long)nums[i]-t<=(long)nums[j] && (long)nums[j]<=(long)t+nums[i]){
                    dp[j]=max(dp[j],1+dp[i]);
                }
            }
            }
        }
        return dp[n-1];
    }
};