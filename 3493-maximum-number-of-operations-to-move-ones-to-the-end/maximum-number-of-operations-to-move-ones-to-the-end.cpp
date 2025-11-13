class Solution {
public:
    int maxOperations(string s) {
        int i=0;
        int n=s.size();
        int x=0,ans=0;
        while(i<n){
            while(i<n&& s[i]=='1') {
                x++;
                i++;
            }
            if(i==n) break;
            while(i<n&& s[i]=='0') i++;
            ans+=x;
        }
        return ans;
    }
};