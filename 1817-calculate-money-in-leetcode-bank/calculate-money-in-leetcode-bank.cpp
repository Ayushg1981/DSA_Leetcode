class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int x=28,a=1;;
        while(n>=7){
            ans+=x;
            x+=7;
            n-=7;
            a++;
        }
        while(n--){
            ans+=a;
            a++;
        }
        return ans;
    }
};