class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0;
        int ans=0;
        while(j<nums.size()){
            long long x=(long long)k*nums[i];
            while(j<nums.size()&& nums[j]<=x) j++;
            ans=max(ans,j-i);
            i++;
        }
        return nums.size()-ans;
    }
};