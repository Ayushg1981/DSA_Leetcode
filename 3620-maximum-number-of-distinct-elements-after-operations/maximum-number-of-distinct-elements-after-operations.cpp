class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1;
        nums[0]=nums[0]-k;
        for(int i=1;i<nums.size();i++){
            int x=nums[i];
            nums[i]=max(nums[i]-k,nums[i-1]+1);
            if(nums[i]<=x+k) ans++;
            else nums[i]=x+k;
        }
        return ans;
    }
};