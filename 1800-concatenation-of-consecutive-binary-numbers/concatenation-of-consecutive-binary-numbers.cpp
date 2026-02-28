class Solution {
public:
    int concatenatedBinary(int n) {
        long long x=1;
        int y=2;
        for(int i=2;i<=n;i++){
            if(i>=pow(2,y)) y++;
            x=x<<y;
            x=x|i;
            x=x%1000000007;
        }
        return x;
    }
};