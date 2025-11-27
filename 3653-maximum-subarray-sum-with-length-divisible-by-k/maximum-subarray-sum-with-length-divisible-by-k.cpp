class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long x=0;
        vector<long long> v(k,INT_MAX);
        
        for(int i=0;i<k;i++){
            x+=nums[i];
            v[i]=min(x,v[i]);
            
        }
        long long ans=x;
        for(int i=k;i<nums.size();i++){
            x+=nums[i];
            if((i+1)%k==0) ans=max(ans,x);
            ans=max(ans,x-v[(i)%k]);
            v[(i)%k]=min(v[(i)%k],x);
        }
        return ans;
    }
};