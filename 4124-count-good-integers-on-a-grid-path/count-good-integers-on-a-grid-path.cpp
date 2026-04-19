class Solution {
public:
    long long dp[20][2][20];
    long long f(int i,bool flag,int l,string& s,vector<bool>& idx){
        if(i==16) return 1;
        if(dp[i][flag][l]!=-1) return dp[i][flag][l];
        int ub=(flag)?s[i]-'0':9;
        long long x=0;
        for(int j=0;j<=ub;j++){
            int nl = l;
            if(idx[i]){
                if( j<l) continue;
                nl=j;
            }
            x+=f(i+1,flag && j==ub,nl,s,idx);
        }
        return dp[i][flag][l]=x;
    }
    long long countGoodIntegersOnPath(long long l, long long r, string d) {
        memset(dp,-1,sizeof dp);
        vector<bool> idx(16,0);
        int x=0;
        idx[0]=true;
        for(int i=0;i<6;i++){
            if(d[i]=='D') x+=4;
            else x++;
            idx[x]=true;
        }
        string sl=to_string(l-1);
        while(sl.size()<16){
            sl='0'+sl;
        }
        string sr=to_string(r);
        while(sr.size()<16){
            sr='0'+sr;
        }
        long long a=f(0,true,0,sr,idx);
        memset(dp,-1,sizeof dp);
        long long b=f(0,true,0,sl,idx);
        return a-b;
    }
};