class Solution {
public:
    int dp[1005][52];
    int f(int idx,vector<int>& nums,int k){
        if(k==1){
            int x=0;
            for(int i=idx;i<nums.size();i++){
                x+=nums[i];
            }
            return x;
        }
        if(dp[idx][k]!=-1) return dp[idx][k];
        int x=0;
        int ans=INT_MAX;
        for(int i=idx;i<nums.size();i++){
            x+=nums[i];
            ans=min(ans,max(x,f(i+1,nums,k-1)));
        }
        return dp[idx][k]=ans;
    }
    int splitArray(vector<int>& nums, int k) {
        memset(dp,-1,sizeof dp);
        return f(0,nums,k);
    }
};