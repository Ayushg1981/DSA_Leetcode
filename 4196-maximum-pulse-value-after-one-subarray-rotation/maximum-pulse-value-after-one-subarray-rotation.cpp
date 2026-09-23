class Solution {
public:
    long long max_subarray_sum_even(vector<int>&nums){
        vector<long long>pmin = {(long long)1e12 , (long long)1e12};
        long long ans = 0,pre = 0;
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            ans = max(ans, pre - pmin[i%2]);
            if(i%2)ans = max(ans , pre);
            pmin[i%2] = min(pmin[i%2],pre);
        }
        return ans;
        // curr_sub - prev_min -> for max
    }
    long long maxValue(vector<int>& nums) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0)nums[i]*=(-1);
        }
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        long long fsum = -1*sum;
        // fsum => max_sub
        // fsum - (-max_sum) + max_sub
        // fsum + 2*max_sub
        long long max_sub = max_subarray_sum_even(nums);
        return  max(fsum , 2*max_sub+fsum);
    }
};