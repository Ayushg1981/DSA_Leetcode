class Solution {
public:
    bool canAliceWin(int n) {
        bool ans=false;
        int x=10;
        while(n>=x){
            n-=x;
            x--;
            ans= !ans;
        }
        return ans;
    }
};