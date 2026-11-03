class Solution {
public:
    int minMoves(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=max(x,nums[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(x-nums[i]);
        }
        return ans;
    }
};