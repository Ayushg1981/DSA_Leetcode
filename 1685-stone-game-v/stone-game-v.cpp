class Solution {
public:
    int dp[505][505];
    int f(int i,int j,int sum,vector<int>& val){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        int s=0;
        for(int k=i;k<j;k++){
            s+=val[k];
            sum-=val[k];
            if(s<sum) ans=max(ans,f(i,k,s,val)+s);
            else if(s>sum) ans=max(ans,f(k+1,j,sum,val)+sum);
            else{
                ans=max(ans,f(i,k,s,val)+s);
                ans=max(ans,f(k+1,j,sum,val)+sum);
            }
        }
        return dp[i][j]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        memset(dp,-1,sizeof dp);
        int sum=0;
        int n=stoneValue.size();
        for(int i=0;i<n;i++){
            sum+=stoneValue[i];
        }
        return f(0,n-1,sum,stoneValue);
    }
};