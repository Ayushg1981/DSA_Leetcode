class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int a=1,b=1;
        int ans=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) a=b=1;
            else if(nums[i]>nums[i+1]){
                a++;
                b=1;
            }
            else{
                b++;
                a=1;
            }
            ans=max(ans,max(a,b));
        }
        return ans;
    }
};