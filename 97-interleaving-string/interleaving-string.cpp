class Solution {
public:
    int dp[102][102][202];
    bool f(string & s1, string& s2, string& s3,int i,int j,int k,bool flag,int a,int b){
        if(k==s3.size()) return abs(a-b)<=1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(i<s1.size() && j<s2.size() && s1[i]==s2[j] && s1[i]==s3[k]){
            if(flag) return dp[i][j][k]=f(s1,s2,s3,i+1,j,k+1,flag,a,b) || f(s1,s2,s3,i,j+1,k+1,!flag,a,b+1);
            else return dp[i][j][k]=f(s1,s2,s3,i+1,j,k+1,!flag,a+1,b) || f(s1,s2,s3,i,j+1,k+1,flag,a,b);
        }
        else if(i<s1.size() && s1[i]==s3[k]){
            if(flag) return dp[i][j][k]=f(s1,s2,s3,i+1,j,k+1,flag,a,b);
            else return dp[i][j][k]=f(s1,s2,s3,i+1,j,k+1,!flag,a+1,b);
        }
        else if(j<s2.size() && s2[j]==s3[k]){
            if(flag) return dp[i][j][k]=f(s1,s2,s3,i,j+1,k+1,!flag,a,b+1);
            else return dp[i][j][k]=f(s1,s2,s3,i,j+1,k+1,flag,a,b);
        }
        else return dp[i][j][k]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        if(s1.size()+s2.size()!=s3.size()) return false;
        return f(s1,s2,s3,0,0,0,true,1,0)||f(s1,s2,s3,0,0,0,false,0,1);
    }
};