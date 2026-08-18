class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(n>k && k>1){
            if(nums[0]==nums[n-1]) return -1;
            int x=0;
            int y=0;
            for(int i=1;i<n-1;i++){
                if(nums[i]==nums[0]) x++;
                if(nums[n-1]==nums[i]) y++;
            }
            if(x==0 && y==0) return max(nums[0],nums[n-1]);
            else if(x==0) return nums[0];
            else if(y==0) return nums[n-1];
            else return -1;
        }
        else if(k==1){
            unordered_map<int,int> m;
            for(int i=0;i<n;i++){
                m[nums[i]]++;
            }
            int ans=-1;
            for(auto x:m){
                if(x.second==1){
                    ans=max(ans,x.first);
                }
            }
            return ans;
        }
        else{
            int ans=-1;
            for(auto x:nums){
                    ans=max(ans,x);
            }
            return ans;
        }
    }
};