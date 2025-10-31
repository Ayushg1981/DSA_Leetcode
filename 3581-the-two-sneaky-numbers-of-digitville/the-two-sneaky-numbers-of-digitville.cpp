class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        vector<int> v;
        sort(nums.begin(), nums.end());
        while (i != 0) {
            if ((nums[i] - nums[i - 1]) != 1) {
                v.push_back(nums[i]);
            }
            i--;
        }
        return v;
    }
};