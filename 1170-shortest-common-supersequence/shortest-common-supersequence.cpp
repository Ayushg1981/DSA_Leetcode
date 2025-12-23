class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        if(text1[0]==text2[0]) dp[0][0]=1;
        for(int i=1;i<m;i++){
            if(text1[0]==text2[i]) dp[0][i]=1;
            else dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<n;i++){
            if(text1[i]==text2[0]) dp[i][0]=1;
            else dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(text1[i]==text2[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int x=dp[n-1][m-1];
        string s="";
        int i=n-1,j=m-1;
        while(i>=0 && j>=0 && x>0){
            if(j>0&& dp[i][j-1]==x) j--;
            else if(i>0&&dp[i-1][j]==x) i--;
            else if(x>0){
                s=text1[i]+s;
                i--;
                j--;
                x--;
            }
        }
        string ans="";
        i=0,j=0;
        int k=0;
        while(i<n && j<m && k<s.size()){
            while(i<n && text1[i]!=s[k]){
                ans+=text1[i];
                i++;
            }
            while(j<m && text2[j]!=s[k]){
                ans+=text2[j];
                j++;
            }
            ans+=s[k];
            i++;
            j++;
            k++;
        }
        while(i<n){
            ans+=text1[i];
            i++;
        }
        while(j<m){
            ans+=text2[j];
            j++;
        }
    return ans;
    }
};