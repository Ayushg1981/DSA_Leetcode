class Solution {
public:
    int reverse(int x){
        int y=0;
        while(x){
            y=y*10+x%10;
            x/=10;
        }
        return y;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,i-mp[nums[i]]);
            }
            mp[reverse(nums[i])]=i;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};