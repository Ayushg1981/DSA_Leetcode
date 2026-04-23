class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,tuple<long long,int,long long>> mp,mp2;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]={1,i,0};
            }
            else{
                auto [f,idx,cost]=mp[nums[i]];
                mp[nums[i]]={f+1,idx,cost+i-idx};
            }
        }
        vector<long long> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(mp2.find(nums[i])==mp2.end()){
                auto [f,idx,cost]=mp[nums[i]];
                ans[i]=cost;
                mp2[nums[i]]={1,i,cost};
            }
            else{
                auto [f1,idx1,cost1]=mp[nums[i]];
                auto [f2,idx2,cost2]=mp2[nums[i]];
                ans[i]=cost2+f2*(i-idx2)-((f1-f2)*(i-idx2));
                mp2[nums[i]]={f2+1,i,ans[i]};
            }
        }
        return ans;
    }
};