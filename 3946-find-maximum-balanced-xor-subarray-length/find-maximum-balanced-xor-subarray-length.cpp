class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> pre(n,{0,0});
        unordered_map<int,unordered_map<int,int>> mp;
        if(nums[0]%2==0){
            pre[0]={nums[0],1};
            mp[nums[0]][1]=0;
        }
        else{
            pre[0]={nums[0],-1};
            mp[nums[0]][-1]=0;
        }
        int ans=0;
        for(int i=1;i<n;i++){
            pre[i].first=pre[i-1].first^nums[i];
            if(nums[i]%2==0) pre[i].second=pre[i-1].second+1;
            else pre[i].second=pre[i-1].second-1;
            if(pre[i].first==0&&pre[i].second==0){
                ans=i+1;
                continue;
            }
            if(mp.find(pre[i].first)!=mp.end()){
                auto& x=mp[pre[i].first];
                if(x.find(pre[i].second)!=x.end()){
                    ans=max(ans,i-x[pre[i].second]);
                }
                else mp[pre[i].first][pre[i].second]=i;
            }
            else mp[pre[i].first][pre[i].second]=i;
        }
        return ans;
    }
};