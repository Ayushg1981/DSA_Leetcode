class Solution {
public:
    int dp[3005];
    int f(vector<vector<int>>& pairs,int i,int k){
        if(i==pairs.size()) return 0;
        if(dp[k]!=-1) return dp[k];
        int x=0;
        if(pairs[i][0]+1005>k){
            x=1+f(pairs,i+1,pairs[i][1]+1005);
        }
        return dp[k]=max(x,f(pairs,i+1,k));
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
        return f(pairs,0,0);
    }
};