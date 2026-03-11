class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int x=INT_MAX^n;
        int ans=0,a=1;
        while(n>0){
            if(x&1==1) ans+=a;
            a*=2;
            x=x>>1;
            n=n>>1;
        }
        return ans;
    }
};