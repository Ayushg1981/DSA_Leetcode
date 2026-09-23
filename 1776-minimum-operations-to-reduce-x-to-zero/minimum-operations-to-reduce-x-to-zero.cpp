class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        int n=v.size();
        unordered_map<int,int> mp;
        mp[v[0]]=0;
        for(int i=1;i<n;i++){
            v[i]+=v[i-1];
            mp[v[i]]=i;
        }
        int sum=v[n-1];
        if(sum==x) return n;
        if(x>sum) return -1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int y=sum-v[i];
            if(y>x) continue;
            if(y==x) ans=min(ans,n-i-1);
            else{
                if(mp.find(x-y)!=mp.end()){
                    ans=min(ans,n-i+mp[x-y]);
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};