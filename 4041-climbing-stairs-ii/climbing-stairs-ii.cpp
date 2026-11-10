class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int i=3;
        vector<int> dp(n+5,0);
        dp[0]=costs[0]+1;
        if(1<n) dp[1]=min(dp[0]+costs[1]+1,costs[1]+4);
        if(2<n) dp[2]=min({costs[2]+9,dp[0]+costs[2]+4,dp[1]+costs[2]+1});
        while(i<n){
            dp[i]=min({dp[i-3]+costs[i]+9,dp[i-2]+costs[i]+4,dp[i-1]+costs[i]+1});
            i++;
        }
        return dp[n-1];
    }
};