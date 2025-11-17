class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int x=1000000;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) x++;
            else{
                if(x>=k) x=0;
                else return false;
            }
        }
        return true;
    }
};