class Solution {
public:
    long long dp[100005];
    long long f(int i,vector<pair<int,long long>> & arr){
        if(i<0) return INT_MIN;
        if(dp[i]!=-1) return dp[i];
        long long ans=LLONG_MIN;
        int j=i-1;
        while(j>=0 && arr[j].first>=arr[i].first-2) j--;
        if(j==-1) return dp[i]=arr[i].second;
        ans=max(ans,f(j,arr));
        if(j-1>=0) ans=max(ans,f(j-1,arr));
        if(j-2>=0) ans=max(ans,f(j-2,arr));
        return dp[i]=ans+arr[i].second;
    }
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());
        vector<pair<int,long long>> v;
        int j=0;
        v.push_back({power[0],power[0]});
        for(int i=1;i<power.size();i++){
            if(power[i]==v[j].first) v[j].second+=power[i];
            else{
                v.push_back({power[i],power[i]});
                j++;
            }
        }
        int n=v.size();
        if(n==1) return v[0].second;
        memset(dp,-1,sizeof(dp));
        return max({f(n-1,v),f(n-2,v),f(n-3,v)});
    }
};