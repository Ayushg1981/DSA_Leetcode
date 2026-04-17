class Solution {
public:
    int f(int i , int j , vector<int> & arr ,  vector<vector<int>> &dp) {
        if(i>j) return 0;
        if(i==j){ 
            int x=arr[i];
            if(j+1<arr.size()) x*=arr[j+1];
            if(i-1>=0) x*=arr[i-1];
            return x;
        }
        if(dp[i][j] != -1) return dp[i][j] ;
        int ans = INT_MIN ;
        for(int k = i ; k<=j ; k++) {
            int x=arr[k];
            if(j+1<arr.size()) x*=arr[j+1];
            if(i-1>=0) x*=arr[i-1];
            ans = max(ans,f(i,k-1,arr,dp)+f(k+1,j,arr,dp)+x);
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