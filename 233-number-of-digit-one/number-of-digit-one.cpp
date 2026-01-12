class Solution {
public:
    int dp[40][2][40];
    int f(int i,bool flag,int cnt,string& s){
        if(i==s.size()) return cnt;
        if(dp[i][flag][cnt]!=-1) return dp[i][flag][cnt];
        int ub=(flag)?s[i]-'0':9;
        int x=0;
        for(int j=0;j<=ub;j++){
            x+=f(i+1,flag && j==ub,cnt+(j==1),s);
        }
        return dp[i][flag][cnt]=x;
    }
    int countDigitOne(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return f(0,1,0,s);
    }
};