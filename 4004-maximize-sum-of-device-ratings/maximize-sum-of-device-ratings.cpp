class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n=units.size();
        int m=units[0].size();
        long long mn=INT_MAX,sum=0,ans=0;
        if(m==1){
            for(int i=0;i<n;i++){
                ans+=units[i][0];
            }
            return ans;
        }
        for(int i=0;i<n;i++){
            sort(units[i].begin(),units[i].end());
            sum+=units[i][1];
            mn=min(mn,(long long)units[i][0]);
        }
        for(int i=0;i<n;i++){
            ans=max(ans,sum+mn-units[i][1]);
        }
        return ans;
    }
};