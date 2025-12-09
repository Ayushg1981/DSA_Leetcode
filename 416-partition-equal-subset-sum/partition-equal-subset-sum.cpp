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
        return f(nums,0,c/2);
    }
};