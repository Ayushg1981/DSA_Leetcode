class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MIN;

        if(k==0 || n==1){
            int x=0;
            for(int i=0;i<nums.size();i++){
                x+=nums[i];
                ans=max(ans,x);
                if(x<0) x=0;
            }
            return ans;
        }

        for(int i=0;i<n;i++){
            ans=max(ans,nums[i]);
        }
        if(ans<0) return ans;

        vector<vector<int>> dp(n,vector<int>(n,0)),left(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            priority_queue<int> pqmax;
            priority_queue<int,vector<int>,greater<int>> pqmin;
            int s=0,x=0,y=0;
            
            for(int j=0;j<i;j++){
                pqmin.push(nums[j]);
                y+=nums[j];
                if(pqmin.size()>k){
                    y-=pqmin.top();
                    pqmin.pop();
                }
            }
            left[i][n-1]=y;
            for(int j=i;j<n;j++){
                s+=nums[j];
                if(nums[j]<0){
                    pqmax.push(nums[j]);
                    x+=nums[j];
                }
                if(pqmax.size()>k){
                    x-=pqmax.top();
                    pqmax.pop();
                }
                dp[i][j]=s-x;
            }

            for(int j=n-1;j>i;j--){
                pqmin.push(nums[j]);
                y+=nums[j];
                if(pqmin.size()>k){
                    y-=pqmin.top();
                    pqmin.pop();
                }
                left[i][j-1]=y;
            }

            for(int j=0;j<n;j++){
                ans=max(ans,dp[i][j]+left[i][j]);
            }
        }


        return ans;
    }
};