class Solution {
public:
    int f(int i , int j , vector<int> & arr ,  vector<vector<int>> &dp) {
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j] ;
        int ans = INT_MIN ;
        for(int k = i ; k<=j ; k++) {
            ans = max(ans,f(i,k-1,arr,dp)+f(k+1,j,arr,dp)+arr[k]*arr[j+1]*arr[i-1]);
        }
        return dp[i][j] = ans ;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size() ;
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(305 , vector<int>(305 , -1)) ;
        return f(1 , n , nums , dp) ;
    }
};