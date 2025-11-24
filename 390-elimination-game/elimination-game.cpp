class Solution {
public:
    int lastRemaining(int n) {
        int ans=1;
        bool flag=true;
        int x=1;
        while(n>1){
            if(flag || n%2==1){
                ans+=x;
                
            }
            x*=2;
            n/=2;
            flag=!flag;
        }
        return ans;
    }
};