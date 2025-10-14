class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k==1) return true;
        int n=nums.size();
        if(n<2*k) return false;
        int i=0,j=0;
        while(j<n){
            while(j<n-1 && nums[j]<nums[j+1]) j++;
            if(j-i+1>=2*k) return true;
            if(j-i+1>=k){
                j++;
                i=j;
                if(n-j<k) return false;
                while(j<n-1 && nums[j]<nums[j+1]) j++;
                if(j-i+1>=k) return true;
            }
            else{
                j++;
                i=j;
            }
        }
        return false;
    }
};