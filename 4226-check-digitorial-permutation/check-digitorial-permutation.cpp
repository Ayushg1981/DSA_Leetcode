class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int x=0;
        vector<int> b={1,1,2,6,24,120,720,5040,40320,362880};
        int y=n;
        vector<int> c(10,0),d(10,0);
        while(n>0){
            int a=n%10;
            n/=10;
            x+=b[a];
            c[a]++;
        }
        while(x>0){
            int a=x%10;
            x/=10;
            d[a]++;
        }
        return c==d;
    }
};