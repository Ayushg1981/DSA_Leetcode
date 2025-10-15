class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int k=1;
        int i=0,j=0;
        while(j<n){
            while(j<n-1 && nums[j]<nums[j+1]) j++;
            k=max(k,(j-i+1)/2);
            int a=j-i+1;                
            j++;
            i=j;
            while(j<n-1 && nums[j]<nums[j+1]) j++;
            k=max(k,min(a,j-i+1));
        }
        return k;
    }
};