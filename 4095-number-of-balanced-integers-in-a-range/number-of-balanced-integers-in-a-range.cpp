class Solution {
public:
    long long dp[16][2][200][200];
    long long f(int i,bool flag,int c1,int c2,string& s){
        if(i==s.size()){
            if(c1==0 || c2==0) return 0;
            return c1==c2;
        }
        if(dp[i][flag][c1][c2]!=-1) return dp[i][flag][c1][c2];
        int ub=(flag)?s[i]-'0':9;
        long long x=0;
        for(int j=0;j<=ub;j++){
            x+=f(i+1,flag && j==ub,c1+((i%2==0)?j:0),c2+((i%2==1)?j:0),s);
        }
        return dp[i][flag][c1][c2]=x;
    }
    long long countBalanced(long long low, long long high) {
        memset(dp,-1,sizeof(dp));
        string s=to_string(low-1);
        long long x=f(0,1,0,0,s);
        memset(dp,-1,sizeof(dp));
        s=to_string(high);
        long long y=f(0,1,0,0,s);
        return y-x;
    }
};