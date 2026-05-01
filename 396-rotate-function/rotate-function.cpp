class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans=0,sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans+=nums[i]*i;
        }
        int last=ans;
        for(int i=1;i<n;i++){
            int x=last-(sum-nums[i-1])+(n-1)*nums[i-1];
            ans=max(ans,x);
            last=x;
        }
        return ans;
    }
};