class Solution {
public:
    int f(int i,int j,vector<int>& nums){
        if(j==i) return nums[i];
        return max(nums[i]-f(i+1,j,nums),nums[j]-f(i,j-1,nums));
    }
    bool predictTheWinner(vector<int>& nums) {
        return (f(0,nums.size()-1,nums)>=0);
    }
};