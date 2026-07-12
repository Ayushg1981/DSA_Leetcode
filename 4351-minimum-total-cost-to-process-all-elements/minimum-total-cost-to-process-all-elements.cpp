class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long cost=0;
        int x=k;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=x) x-=nums[i];
            else{
                int y=nums[i]-x;
                cost+=y/k;
                if(y%k!=0){
                    cost++;
                    x=k-(y%k);
                }
                else x=0;
            }
        }
        return ((cost%1000000007)*((cost+1)%1000000007))%1000000007*500000004%1000000007;
    }
};