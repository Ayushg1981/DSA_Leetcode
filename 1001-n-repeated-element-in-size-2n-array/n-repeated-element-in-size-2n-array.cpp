class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (int i = 2, n = nums.size(); i < n; ++i){
            if (nums[i] == nums[i - 1] || nums[i] == nums[i - 2]) return nums[i];
        }
        return nums[0];
    }
};